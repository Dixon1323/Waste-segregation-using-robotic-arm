import cv2
from ultralytics import YOLO
import serial


ser = serial.Serial('/dev/cu.usbserial-1410', 115200)
# Load YOLO model
model = YOLO("best.pt")  # Update to your model's path

# Start video capture (use Pi Camera or USB camera)
# cap = cv2.VideoCapture("test.mp4")
cap = cv2.VideoCapture(0)

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Failed to capture frame")
            break

        # Perform YOLO prediction
        results = model.predict(source=frame, conf=0.5, device="cpu")  # CPU inference
        detections = results[0].boxes.data if len(results) > 0 else []

        # Process detections
        for detection in detections:
            category = int(detection[5])  # Class ID from YOLO
            confidence = detection[4]    # Confidence score
            x1, y1, x2, y2 = map(int, detection[:4])  # Bounding box coordinates

            if confidence > 0.5:
                # Map class ID to category name
                category_names = ['Biodegradable', 'Degradable', 'Non-Biodegradable', 'Non-Degradable']
                category_name = category_names[category] if category < len(category_names) else "Unknown"

                # Print detected category
                # print(f"Detected: {category_name}, Confidence: {confidence:.2f}")
                if(category_name=="Degradable"):
                # Draw bounding box and label on the frame
                    cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)  # Green box
                    cv2.putText(frame, f"{category_name} ({confidence:.2f})", 
                            (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    b="1"
                    ser.write(b.encode())
                    print("data sent: 1")


                if(category_name=="Non-Biodegradable"):
                # Draw bounding box and label on the frame
                    cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)  # Green box
                    cv2.putText(frame, f"{category_name} ({confidence:.2f})", 
                            (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    b="2"
                    ser.write(b.encode())  
                    print("data sent: 2")

        # Display the frame
        cv2.imshow("Waste Detection", frame)

        # Break on 'q' key press
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except KeyboardInterrupt:
    print("Interrupted by user")

finally:
    cap.release()
    cv2.destroyAllWindows()
