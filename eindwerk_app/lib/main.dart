import 'package:flutter/material.dart';
import 'homepage.dart';
import 'package:flutter/services.dart';
import 'package:firebase_core/firebase_core.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized(); //voorkomt error
  await Firebase.initializeApp(); //start de firebase database
  runApp(MyApp()); //start de app
  SystemChrome.setEnabledSystemUIOverlays([]); //zet het sherm in fullscreen
}

class MyApp extends StatelessWidget {
  //de myapp class
  @override
  Widget build(BuildContext context) {
    //built de widget
    return MaterialApp(
      //returns de witdget materialapp
      debugShowCheckedModeBanner:
          false, //laat een debug banner verdwijnen in de hoek
      title: 'REG App', //titel van de app
      theme: ThemeData(
        scaffoldBackgroundColor: Color.fromRGBO(39, 66, 83,
            100), //zet de achtergrond van de app naar iets zwart achtig
        primarySwatch:
            Colors.lightBlue, //geeft de objecten standaard kleur blauw
        visualDensity: VisualDensity
            .adaptivePlatformDensity, //standaard lijn geen idee wat het doet
      ),
      home: Myhomepage(), //zegt dat de home pagina Myhomepage is
    );
  }
}
