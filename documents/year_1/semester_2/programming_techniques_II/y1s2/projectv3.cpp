//CHOH JING YI A23CS0296
//LIOW JIA FENG A23CS0302
//CHUA SHANG YEET A23CS0297
//TAY CHING XIAN A23CS0307

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Name {
private:
    string firstName;
    string lastName;

public:
    Name(string fN = "", string lN = "") {
        firstName = fN;
        lastName = lN;
    }

    void setFirstName(string fN) {
        firstName = fN;
    }

    void setLastName(string lN) {
        lastName = lN;
    }

    string getFullName() const {
        return firstName + " " + lastName;
    }
};

class Notification {
protected:
    string message;
    string time;

public:
    Notification() {}
    Notification(string msg, string t) : message(msg), time(t) {}

    virtual void setReminder(string t, string msg) {
        time = t;
        message = msg;
    }

    virtual void displayNotification() const = 0;

    virtual ~Notification() {}

};

class SMSNotification : public Notification {
public:
    SMSNotification() : Notification() {}
    SMSNotification(string msg, string t) : Notification(msg, t) {}

    void displayNotification() const override {
        cout << "SMS Notification:\n";
        cout << "Time: " << time << ", Message: " << message << endl;
    }
};

class EmailNotification : public Notification {
public:
    EmailNotification() : Notification() {}
    EmailNotification(string msg, string t) : Notification(msg, t) {}

    void displayNotification() const override {
        cout << "Email Notification:\n";
        cout << "Time: " << time << ", Message: " << message << endl;
    }
};

class FoodSuggestion {
private:
    Notification *notification; 

    string foodItems[5] = {"murtabak", "roti telur", "mee goreng", "laksa", "satay"};
    double foodCalories[5] = {722, 414, 660, 436, 365};

    string suggestFood[3] = {
        "Chicken & Broccoli Stir Fry with Brown Rice",
        "Rainbow Veggie Pocket with Black Beans, Apple",
        "Apple Turkey Gyro, Sunshine Salad"
    };
    double suggestFoodCalories[3] = {446, 459, 443};

    string marketNames[3] = {"UTM Market", "U Shop UTM", "antar2U Mart"};
    string marketAddresses[3] = {
        "Address: Pejabat Pos Universiti Teknologi Malaysia, S38 Johor Bahru, Johor",
        "Address: Shop UTM, 80990 Johor Bahru, Johor",
        "Address: B-2-11 S44 UTMXCITE Universiti Teknologi Malaysia Skudai, 81300 Johor Bahru, Johor"
    };

    

public:
    FoodSuggestion(Notification *notif) : notification(notif) {}

    void searchCalories() {
        string food;
        bool found = false;
        cin.ignore();
        do {
            cout << "What did you eat just now? ";
            getline(cin, food);

            found = false;
            for (int i = 0; i < 5; i++) {
                if (foodItems[i] == food) {
                    cout << "Calories in " << food << ": " << foodCalories[i] << endl;
                    found = true;
                    if (foodCalories[i] > 500) {
                        notification->setReminder("Now", "High calorie food detected: " + food);
                        notification->displayNotification();
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Sorry, we don't have information on the food you mentioned. Please try again.\n";
            }
        } while (!found);
    }

    void getSuggestedFood() const {
        cout << "\nSuggested Healthy Foods:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << suggestFood[i] << " - " << suggestFoodCalories[i] << " calories" << endl;
        }
        cout << "\n";
    }

    void getMarketAddress() const {
        for (int i = 0; i < 3; i++) {
            cout << "Market: " << marketNames[i] << " Address: " << marketAddresses[i] << endl;
        }
    }

    void displayFoodSuggestionAndMarket() const {
        getSuggestedFood();
        getMarketAddress();
    }
};

class OverallHealth {
public:
    string analyzeHealthRisks(double bmi) {
        if (bmi < 18.5) {
            return "Underweight: Increased risk of malnutrition, osteoporosis, and anemia.";
        } else if (bmi >= 18.5 && bmi < 24.9) {
            return "Normal weight: Low risk (healthy range).";
        } else if (bmi >= 25.0 && bmi < 29.9) {
            return "Overweight: Increased risk of cardiovascular diseases, diabetes, and joint problems.";
        } else {
            return "Obesity: High risk of severe cardiovascular diseases, diabetes, and other health issues.";
        }
    }

    string suggestImprovements(double bmi) {
        if (bmi < 18.5) {
            return "Suggestions: Increase calorie intake with nutrient-rich foods, consult a healthcare provider.";
        } else if (bmi >= 18.5 && bmi < 24.9) {
            return "Suggestions: Maintain your healthy lifestyle with a balanced diet and regular exercise.";
        } else if (bmi >= 25.0 && bmi < 29.9) {
            return "Suggestions: Engage in regular physical activity, adopt a balanced diet, avoid sugary and high-fat foods.";
        } else {
            return "Suggestions: Consult a healthcare provider for a personalized weight loss plan, increase physical activity, focus on a balanced and reduced-calorie diet.";
        }
    }

    void displayOverallHealth(double bmi) {
        cout << analyzeHealthRisks(bmi) << endl;
        cout << suggestImprovements(bmi) << endl;
    }
};

class BMIMonitor {
private:
    double height;
    double weight;
    double bmi;
    OverallHealth &overallHealth; 

    double calculateBMI() {
        return weight / (height * height);
    }

public:
    BMIMonitor(double h, double w, OverallHealth &health) : height(h), weight(w), overallHealth(health) {}

    void calculateAndDisplayBMI() {
        bmi = calculateBMI();
        cout << fixed << setprecision(2);
        cout << "Your BMI is: " << bmi << endl;
        overallHealth.displayOverallHealth(bmi);
    }

    double getBMI() const {
        return bmi;
    }
};

class PersonInfo {
protected:
    Name name;
    int age;
    string favoriteSport;

public:
    PersonInfo(Name n = Name(), int a = 0, string f = "") : name(n), age(a), favoriteSport(f) {}

    // Copy constructor
    PersonInfo(const PersonInfo &other) : name(other.name), age(other.age), favoriteSport(other.favoriteSport) {}

    void setPersonalInfo(string fN, string lN, int a, string sport) {
        name.setFirstName(fN);
        name.setLastName(lN);
        age = a;
        favoriteSport = sport;
    }

    string getFavoriteSport() const {
        return favoriteSport;
    }

    Name getN() const { return name; }

    string getName() const {
        return name.getFullName();
    }

    int getAge() const {
        return age;
    }
    friend istream& operator>>(istream &in, PersonInfo &p);
};

istream& operator>>(istream &in, PersonInfo &p) {
    string fName, lName, sport;
    int age;
  
    cout << "Enter your first name: ";
    in>>ws;
    getline(in, fName);
    
    cout << "Enter your last name: ";
    getline(in, lName);
    
    cout << "Enter your age: ";
    in >> age;
    
    cout << "Enter your favorite sport: ";
    in.ignore();
    getline(in, sport);
    
    p.setPersonalInfo(fName, lName, age, sport);
    
    return in;
}
class ExerciseMotivation {
private:
    PersonInfo person1;
    PersonInfo person2;
    Notification *notification;

public:
    ExerciseMotivation(Notification *notif) : notification(notif) {}

    void setExerciseDetails(const PersonInfo &p1, const PersonInfo &p2) {
        person1 = p1;
        person2 = p2;
    }

    void displayExerciseMotivation() {
        do {
            if (person1.getFavoriteSport() == person2.getFavoriteSport()) {
                cout << person1.getName() << " and " << person2.getName() << " both enjoy " << person1.getFavoriteSport() << "!" << endl;
                cout << "Suggested time to exercise together: 6:00 PM on Saturday" << endl;
            
                notification->setReminder("6:00 PM on Saturday", person1.getName() + " and " + person2.getName() + " should exercise together.");
                notification->displayNotification();
                break;
            } else {
                cout << person1.getName() << " and " << person2.getName() << " have different favorite sports.\n" << endl;
                cout << "Please enter a new exercise partner's information.\n";

                string fName, lName, sport;
                int age;
                cout << "Enter your exercise partner's first name: ";
                cin>>ws;
                getline(cin, fName);
                cout << "Enter your exercise partner's last name: ";
                getline(cin, lName);
                cout << "Enter your exercise partner's age: ";
                cin >> age;
                cout << "Enter your exercise partner's favorite sport: ";
                cin.ignore(); 
                getline(cin, sport);

                person2.setPersonalInfo(fName, lName, age, sport);
            }
        } while (true);
    }
};

class Feedback {
private:
    ExerciseMotivation &exerciseMotivation; 

public:
    Feedback(ExerciseMotivation &em) : exerciseMotivation(em) {}

    void gatherFeedback() {
    string response;
    exerciseMotivation.displayExerciseMotivation();
    do {
        cout << "Did you enjoy the exercise? (yes/no): ";
        cin >> response;
        if (response == "yes") {
            cout << "Great! Keep up the good work!" << endl;
        } else if (response == "no") {
            cout << "Sorry to hear that. We will try to improve your exercise experience next time." << endl;
        } else {
            cout << "Please type yes or no" << endl;
        }
    } while (response != "yes" && response != "no");
}
};

class HealthReport : public PersonInfo{
private:
    
    BMIMonitor *bmiMonitor;
    string reportDate;

public:
    HealthReport(PersonInfo *p, BMIMonitor *b, string date) : PersonInfo(Name(p->getN()), p->getAge(),p->getFavoriteSport()),bmiMonitor(b),reportDate(date) {}

    void generateDailyReport() {
        
        cout << "\n--- Daily Health Report ---" << endl;
        cout<< "Report Date: "<<reportDate<<endl;
        cout << "Name: " << name.getFullName() << endl;
        cout << "Age: " << age << endl;
        cout << "Favorite Sport: " << favoriteSport << endl;
        bmiMonitor->calculateAndDisplayBMI();
    }
};

int main() {
    SMSNotification smsNotification;
    EmailNotification emailNotification;
    FoodSuggestion foodSuggestion(&smsNotification);
    OverallHealth overallHealth;
    ExerciseMotivation exerciseMotivation(&emailNotification);
    PersonInfo person1, person2;

    cout<<"Welcome to Group Healthy System\n";

    cin >> person1;
    double height, weight;
    cout << "Enter height (m): ";
    cin >> height;
    cout << "Enter weight (kg): ";
    cin >> weight;
    BMIMonitor bmiMonitor(height, weight, overallHealth);

    int choice;
    do {
        cout << "\n--- Health Management System ---\n";
        cout << "1. Get Diet Suggestion\n";
        cout << "2. Calculate and Display BMI\n";
        cout << "3. Match exercise partner\n";
        cout << "4. Feedback for the sport\n";
        cout << "5. Generate Health Report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            foodSuggestion.searchCalories();
            foodSuggestion.displayFoodSuggestionAndMarket();
            cout << endl << "Press Enter to continue..." << endl;
            cin.ignore();
            break;
        }
        case 2: {
            bmiMonitor.calculateAndDisplayBMI();
            cin.ignore();
            cout << endl << "Press Enter to continue..." << endl;
            cin.ignore();

            break;
        }
        case 3: {
            cout << "Please write your exercise partner's name: "<<endl;
            cin>>person2;
            exerciseMotivation.setExerciseDetails(person1, person2);
            exerciseMotivation.displayExerciseMotivation();
            cout << endl << "Press Enter to continue..." << endl;
            cin.ignore();
            break;
        }
        case 4: {
            Feedback feedback(exerciseMotivation);
            feedback.gatherFeedback();
            cin.ignore();
            cout << endl << "Press Enter to continue..." << endl;
            cin.ignore();
            break;
        }
        case 5: {
            string reportDate;
            cout << "Enter report date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, reportDate);
            HealthReport dailyReport(&person1, &bmiMonitor, reportDate);
            dailyReport.generateDailyReport();
            cout << endl;
            cout << endl << "Press Enter to continue..." << endl;
            cin.ignore();
            break;
        }
        case 0:
            cout << "Exiting the system...\n";
            cout<<"Thanks for using Group Healthy System\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}