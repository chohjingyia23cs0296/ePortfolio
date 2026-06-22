import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import '../lib/firebase_options.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  try {
    await Firebase.initializeApp(
      options: DefaultFirebaseOptions.currentPlatform,
    );
    print("Firebase Initialized!");
    
    final db = FirebaseFirestore.instance;
    
    // Query bookings
    final bookingsSnap = await db.collection('bookings').get();
    print("\n--- BOOKINGS ---");
    for (var doc in bookingsSnap.docs) {
      final data = doc.data();
      print("ID: ${doc.id}");
      print("  Date: ${data['date'] != null ? (data['date'] as Timestamp).toDate().toIso8601String() : 'null'}");
      print("  Subject: ${data['subjectName']} (${data['subjectCode']})");
      print("  Class: ${data['studentClass']}");
      print("  Room: ${data['roomId']}");
      print("  Time: ${data['startTime']} - ${data['endTime']}");
      print("  Lecturer: ${data['lecturerName']} (${data['lecturerId']})");
    }
    
    // Query timetableEntries
    final ttSnap = await db.collection('timetableEntries').get();
    print("\n--- TIMETABLE ENTRIES ---");
    for (var doc in ttSnap.docs) {
      final data = doc.data();
      print("ID: ${doc.id}");
      print("  Date: ${data['date'] != null ? (data['date'] as Timestamp).toDate().toIso8601String() : 'null'}");
      print("  Subject: ${data['subjectName']} (${data['subjectCode']})");
      print("  Class: ${data['studentClass']}");
      print("  Room: ${data['room']}");
      print("  Time: ${data['startMinutes']} - ${data['endMinutes']}");
      print("  Lecturer: ${data['lecturerName']} (${data['lecturerId']})");
    }
    
  } catch (e) {
    print("Error: $e");
  }
}
