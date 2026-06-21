// Header files
#include <iostream>
#include <string>
using namespace std;

// Structure to store booking details
struct Booking {
    string bookingId;
    string customerName;
    string phoneNumber;
    string checkInDate;
    string checkOutDate;
    double payment;
    bool isApproved;
    bool isPaid;
};

// Class to manage homestay bookings
class HomestayBooking {
private:
    // Queue implementation 
    Booking bookingQueue[50];  // 
    int front;                  // Front of queue
    int rear;                   // Rear of queue
    const double ROOM_PRICE = 100.00;
    int availableRooms = 3;    // Changed from 5 to 3
    int bookingCounter = 1;

    // Constructor to initialize queue
    public:
    HomestayBooking() {
        front = -1;
        rear = -1;
    }

    private:
    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full 
    bool isFull() {
        return rear == 49;  // MAX - 1 (where MAX is 50)
    }

    // Enqueue operation 
    void enqueue(Booking booking) {
        if (isFull()) {
            cout << "Booking system is full. Cannot add more bookings.\n";
            return;
        }
        if (front == -1) {  // If queue is initially empty
            front = 0;
        }
        rear++;
        bookingQueue[rear] = booking;
    }

    // Dequeue operation 
    Booking dequeue() {
        if (isEmpty()) {
            cout << "No bookings available.\n";
            return Booking();
        }
        Booking temp = bookingQueue[front];
        front++;
        if (front > rear) {  // Reset queue when all elements are removed
            front = rear = -1;
        }
        return temp;
    }

    // Peek operation 
    Booking peek() {
        if (isEmpty()) {
            cout << "No bookings available.\n";
            return Booking();
        }
        return bookingQueue[front];
    }

    // Add function to check date overlap
    bool isDateOverlap(const string& newCheckIn, const string& newCheckOut) {
        int newCheckInDays = dateToDays(newCheckIn);
        int newCheckOutDays = dateToDays(newCheckOut);
        int overlappingBookings = 0;

        // Check against all existing bookings
        for (int i = front; i <= rear && front != -1; i++) {
            int existingCheckInDays = dateToDays(bookingQueue[i].checkInDate);
            int existingCheckOutDays = dateToDays(bookingQueue[i].checkOutDate);

            // Check if dates overlap
            if ((newCheckInDays >= existingCheckInDays && newCheckInDays < existingCheckOutDays) ||
                (newCheckOutDays > existingCheckInDays && newCheckOutDays <= existingCheckOutDays) ||
                (newCheckInDays <= existingCheckInDays && newCheckOutDays >= existingCheckOutDays)) {
                overlappingBookings++;
                if (overlappingBookings >= 3) {  // Changed from checking any overlap to checking if all 3 rooms are booked
                    return true;  // All rooms are booked for these dates
                }
            }
        }
        return false;  // Rooms are still available for these dates
    }

public:
    // View all bookings using display concept from example
    void viewAllBookings() {
        if (isEmpty()) {
            cout << "No bookings in the system.\n";
            return;
        }

        // Create temporary queue for storage
        Booking tempQueue[50];
        int tempFront = -1;
        int tempRear = -1;
        bool foundBookings = false;

        cout << "\nAll Confirmed Bookings:\n";
        cout << "----------------------------------------\n";

        // Display all elements 
        for (int i = front; i <= rear; i++) {
            Booking current = bookingQueue[i];
            
            // Store in temp queue
            if (tempFront == -1) {
                tempFront = 0;
            }
            tempRear++;
            tempQueue[tempRear] = current;

            if (current.isPaid && current.isApproved) {
                cout << "Booking ID: " << current.bookingId << "\n"
                     << "Customer Name: " << current.customerName << "\n"
                     << "Phone: " << current.phoneNumber << "\n"
                     << "Check-in: " << current.checkInDate << "\n"
                     << "Check-out: " << current.checkOutDate << "\n"
                     << "Payment: RM" << current.payment << "\n"
                     << "----------------------------------------\n";
                foundBookings = true;
            }
        }

        // Restore the queue
        front = tempFront;
        rear = tempRear;
        for (int i = tempFront; i <= tempRear; i++) {
            bookingQueue[i] = tempQueue[i];
        }

        if (!foundBookings) {
            cout << "No confirmed bookings found.\n";
        }
    }

    // Make booking (using enqueue)
    void makeBooking() {
        if (availableRooms <= 0) {
            cout << "Sorry, no rooms are currently available.\n";
            return;
        }

        if (isFull()) {
            cout << "Booking system is full. Cannot add more bookings.\n";
            return;
        }

        Booking newBooking;
        cout << "\nEnter customer name: ";
        cin.ignore();
        getline(cin, newBooking.customerName);

        cout << "Enter phone number: ";
        getline(cin, newBooking.phoneNumber);

        cout << "Enter check-in date (DD/MM/YYYY): ";
        getline(cin, newBooking.checkInDate);

        cout << "Enter check-out date (DD/MM/YYYY): ";
        getline(cin, newBooking.checkOutDate);

        // Validate dates
        if (dateToDays(newBooking.checkInDate) >= dateToDays(newBooking.checkOutDate)) {
            cout << "Invalid dates: Check-out date must be after check-in date.\n";
            return;
        }

        // Check for date overlap with existing bookings
        if (isDateOverlap(newBooking.checkInDate, newBooking.checkOutDate)) {
            cout << "Sorry, the homestay is already booked for these dates.\n";
            return;
        }

        int numberOfDays = dateToDays(newBooking.checkOutDate) - dateToDays(newBooking.checkInDate);
        newBooking.payment = ROOM_PRICE * numberOfDays;
        newBooking.bookingId = generateBookingId();
        newBooking.isPaid = false;
        newBooking.isApproved = false;

        cout << "\nBooking Details:\n"
             << "Check-in: " << newBooking.checkInDate << "\n"
             << "Check-out: " << newBooking.checkOutDate << "\n"
             << "Number of days: " << numberOfDays << "\n"
             << "Price per night: RM" << ROOM_PRICE << "\n"
             << "Total payment: RM" << newBooking.payment << "\n\n";

        char payChoice;
        cout << "Proceed with payment? (Y/N): ";
        cin >> payChoice;

        if (toupper(payChoice) == 'Y') {
            newBooking.isPaid = true;
            newBooking.isApproved = true;
            enqueue(newBooking);  // Use enqueue instead of push
            availableRooms--;

            cout << "\nPayment successful!\n"
                 << "Booking confirmed!\n"
                 << "Your booking ID: " << newBooking.bookingId << "\n"
                 << "----------------------------------------\n"
                 << "Receipt:\n"
                 << "Booking ID: " << newBooking.bookingId << "\n"
                 << "Customer Name: " << newBooking.customerName << "\n"
                 << "Check-in: " << newBooking.checkInDate << "\n"
                 << "Check-out: " << newBooking.checkOutDate << "\n"
                 << "Amount Paid: RM" << newBooking.payment << "\n"
                 << "Status: Confirmed\n"
                 << "----------------------------------------\n";
        } else {
            cout << "Booking cancelled due to no payment.\n";
        }
    }

    // Generate booking ID
    string generateBookingId() {
        string id = "A" + to_string(bookingCounter);
        bookingCounter++;
        if (bookingCounter > 99) {  // Reset counter if it exceeds 99
            bookingCounter = 1;
        }
        return id;
    }

     // Convert date string (DD/MM/YYYY) to number of days for calculation
    int dateToDays(const string& dateStr) {
        // Converts date to total days for easy comparison
        // Years * 365 + Months * 30 + Days
        return stoi(dateStr.substr(6)) * 365 + stoi(dateStr.substr(3,2)) * 30 + stoi(dateStr.substr(0,2));
    }

    // Check booking status
    void checkBooking(const string& bookingId) {
        if (isEmpty()) {
            cout << "No bookings available.\n";
            return;
        }

        // Create temporary stack to store bookings while searching
        Booking tempStack[50];
        int tempTop = -1;
        bool found = false;

        // Search through the stack
        while (!isEmpty()) {
            Booking current = dequeue();
            tempStack[++tempTop] = current;  // Save to temp stack

            if (current.bookingId == bookingId) {
                cout << "\nBooking found!\n"
                     << "Customer Name: " << current.customerName << "\n"
                     << "Check-in: " << current.checkInDate << "\n"
                     << "Check-out: " << current.checkOutDate << "\n"
                     << "Status: " << (current.isApproved ? "Approved" : "Pending") << "\n"
                     << "Payment: RM" << current.payment << endl;
                found = true;
            }
        }

        // Restore the original stack
        while (tempTop >= 0) {
            enqueue(tempStack[tempTop--]);
        }

        if (!found) {
            cout << "Booking not found.\n";
        }
    }

    // Check room availability with date range
    void checkAvailability() {
        if (availableRooms <= 0) {
            cout << "Sorry, no rooms are currently available.\n";
            return;
        }

        string checkInDate, checkOutDate;
        cout << "\nEnter check-in date (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, checkInDate);
        
        cout << "Enter check-out date (DD/MM/YYYY): ";
        getline(cin, checkOutDate);

        // Validate input dates
        if (dateToDays(checkInDate) >= dateToDays(checkOutDate)) {
            cout << "Invalid dates: Check-out date must be after check-in date.\n";
            return;
        }

        // Check for existing bookings in this period
        bool isAvailable = !isDateOverlap(checkInDate, checkOutDate);
        int numberOfDays = dateToDays(checkOutDate) - dateToDays(checkInDate);

        cout << "\nAvailability Status for " << checkInDate << " to " << checkOutDate << ":\n";
        cout << "----------------------------------------\n";
        if (isAvailable) {
            cout << "Status: AVAILABLE\n";
            cout << "Number of nights: " << numberOfDays << "\n";
            cout << "Price per night: RM" << ROOM_PRICE << "\n";
            cout << "Total price: RM" << (ROOM_PRICE * numberOfDays) << "\n";
            cout << "\nWould you like to make a booking? (Y/N): ";
            char choice;
            cin >> choice;
            if (toupper(choice) == 'Y') {
                makeBooking();
            }
        } else {
            cout << "Status: NOT AVAILABLE\n";
            cout << "The homestay is already booked for these dates.\n";
            
        }
        cout << "----------------------------------------\n";
    }

    // Cancel a booking by booking ID
    void cancelBooking(const string& bookingId) {
        if (isEmpty()) {
            cout << "No bookings available.\n";
            return;
        }

        Booking tempQueue[50];
        int tempFront = -1;
        int tempRear = -1;
        bool found = false;

        while (!isEmpty()) {
            Booking current = dequeue();
            
            if (current.bookingId == bookingId) {
                if (current.isPaid && current.isApproved) {
                    availableRooms++;  // Free up a room
                    cout << "Booking cancelled successfully!\n";
                    found = true;
                    // Don't enqueue this booking (removing it)
                } else {
                    cout << "Booking is not confirmed yet.\n";
                    if (tempFront == -1) tempFront = 0;
                    tempRear++;
                    tempQueue[tempRear] = current;
                }
            } else {
                if (tempFront == -1) tempFront = 0;
                tempRear++;
                tempQueue[tempRear] = current;
            }
        }

        // Restore the queue without the cancelled booking
        front = tempFront;
        rear = tempRear;
        for (int i = tempFront; i <= tempRear && tempFront != -1; i++) {
            bookingQueue[i] = tempQueue[i];
        }

        if (!found) {
            cout << "Booking not found.\n";
        }
    }

    // Staff authentication
    bool authenticateStaff() {
        string password;
        cout << "Enter staff password: ";
        cin >> password;
        return password == "123";
    }

    // Staff processes the next booking in FIFO order
    void processNextBooking() {
        if (isEmpty()) {
            cout << "No bookings to process.\n";
            return;
        }

        // Always process the first booking in the queue (FIFO)
        Booking nextBooking = dequeue();  // Changed from peek() to dequeue()

        if (nextBooking.isPaid) {
            cout << "Processing Booking ID: " << nextBooking.bookingId << "\n"
                 << "Customer Name: " << nextBooking.customerName << "\n"
                 << "Check-in: " << nextBooking.checkInDate << "\n"
                 << "Check-out: " << nextBooking.checkOutDate << "\n"
                 << "Status: Approved\n";

            // Re-enqueue if not cancelling
            char cancelChoice;
            cout << "Do you want to cancel this booking? (Y/N): ";
            cin >> cancelChoice;

            if (toupper(cancelChoice) == 'Y') {
                availableRooms++;  
                cout << "Booking ID: " << nextBooking.bookingId << " has been cancelled.\n";
            } else {
                enqueue(nextBooking);  // Put booking back at end of queue if not cancelled
                cout << "Booking ID: " << nextBooking.bookingId << " has been processed and returned to queue.\n";
            }
        } else {
            cout << "Booking ID: " << nextBooking.bookingId << " is not paid. Cannot process.\n";
            enqueue(nextBooking);  // Put unpaid booking back at end of queue
        }
    }
};

// Main function
int main() {
    HomestayBooking system;
    int userType;

    do {
        // Main menu display
        cout << "\n=== Homestay Booking System ===" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userType;

        if (userType == 1) {  // Customer menu
            int choice;
            string bookingId;  // Variable to store booking ID for operations that need it
            do {
                // Display customer menu options
                cout << "\n=== Customer Menu ===" << endl;
                cout << "1. Make Booking" << endl;
                cout << "2. Check Booking" << endl;
                cout << "3. Cancel Booking" << endl;
                cout << "4. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                // Handle different menu options using switch statement
                switch (choice) {
                    case 1:
                        // Create a new booking
                        system.makeBooking();
                        break;
                    case 2:
                        // Check status of existing booking using booking ID
                        cout << "Enter booking ID: ";
                        cin >> bookingId;
                        system.checkBooking(bookingId);
                        break;
                    case 3:
                        // Cancel an existing booking using booking ID
                        cout << "Enter booking ID: ";
                        cin >> bookingId;
                        system.cancelBooking(bookingId);
                        break;
                    case 4:
                        // Exit customer menu and return to main menu
                        break;  
                    default:
                        // Handle invalid menu choices
                        cout << "Invalid choice!" << endl;
                }
            } while (choice != 4);  // Continue loop until user chooses to exit
        }
        else if (userType == 2) {  // Staff menu
            if (!system.authenticateStaff()) {
                cout << "Invalid password. Access denied.\n";
                continue;
            }

            int choice;
            do {
                cout << "\n=== Staff Menu ===" << endl;
                cout << "1. View All Bookings" << endl;
                cout << "2. Check Room Availability" << endl;
                cout << "3. Process Next Booking" << endl;
                cout << "4. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout<<endl;
                switch (choice) {
                    case 1:
                        system.viewAllBookings();
                        break;
                    case 2:
                        system.checkAvailability();
                        break;
                    case 3:
                        system.processNextBooking();
                        break;
                    case 4:
                        break; 
                    default:
                        cout << "Invalid choice!" << endl;
                }
            } while (choice != 4);  
        }
        else if (userType == 3) {
            cout << "Thank you for using our system!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (userType != 3);  // Loop until user chooses to exit

    return 0;
}
