import 'package:eindwerk_app/Weekplanning.dart';
import 'package:eindwerk_app/mobile_home.dart';
import 'package:eindwerk_app/responsive.dart';
import 'package:eindwerk_app/tablet_home.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'mobile_gegevens.dart';
import 'tablet_gegevens.dart';
import 'homepage.dart';

class Mygegevenspage extends StatefulWidget {
  //de homepagina class
  @override
  _MygegevenspageState createState() =>
      _MygegevenspageState(); //creërt de pagina
}

class _MygegevenspageState extends State<Mygegevenspage> {
  void click() {
    Navigator.push(
        context, MaterialPageRoute(builder: (context) => Myhomepage()));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      bottomNavigationBar: BottomAppBar(
        //dit is de navigatiebalk onder in de app
        color: Colors.lightBlue,
        child: Row(
          children: [
            IconButton(
              //de optie knop in de navigatiebalk
              icon: Icon(Icons.more_vert),
              onPressed: () {},
              splashColor: Colors.blue,
            ),
            Spacer(), //plaats tussen de knoppen optie en menu
            IconButton(
              //de menu knop in de navigatiebalk
              icon: Icon(
                Icons.home_outlined,
                size: 35,
              ),
              onPressed: this.click,
              splashColor: Colors.blue,
            ),
            Spacer(),
            IconButton(
              //de menu knop in de navigatiebalk
              icon: Icon(Icons.menu),
              onPressed: () {},
              splashColor: Colors.blue,
            ),
          ],
        ),
      ),
      body: responsivelayout(
        tabletbody: Mytabletgegevens(),
        mobilebody: Mymobilegegevens(),
      ),
    );
  }
}
