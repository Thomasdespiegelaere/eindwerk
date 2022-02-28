import 'package:eindwerk_app/Weekplanning.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class Myhomepage extends StatefulWidget {
  //de homepagina class
  @override
  _MyhomepageState createState() => _MyhomepageState(); //creërt de pagina
}

class _MyhomepageState extends State<Myhomepage> {
  //de pagina zelf
  void click() {
    //de functie wanneer de knop van weekplanning wordt ingedrukt
    Navigator.push(
        //verplaats de weekplanning pagina naar de bovenkant van de stapel met pagina's
        context,
        MaterialPageRoute(builder: (context) => Weekplanning()));
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
                icon: Icon(Icons.menu),
                onPressed: () {},
                splashColor: Colors.blue,
              ),
            ],
          ),
        ),
        floatingActionButton: FloatingActionButton(
          //dit is de home knop
          child: Icon(
            Icons.home_outlined,
            color: Colors.black,
          ),
          onPressed: () {},
          splashColor: Colors.blue,
        ),
        floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
        body: Container(
          decoration: BoxDecoration(
            image: DecorationImage(
              image: AssetImage("assets/images/smart-home-automation-2.jpg"),
              fit: BoxFit.cover,
              colorFilter: new ColorFilter.mode(
                  Colors.black.withOpacity(0.2), BlendMode.dstATop),
            ),
          ),
          child: Column(
            //dit is de layout van de app zelf
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              //Image.asset('assets/images/smart-home-automation-2.jpg'),
              Wrap(
                //een rij met twee knoppen erin om naar de pagina's te gaan
                spacing: 30,
                children: [
                  SizedBox(
                    width: 30,
                    height: 150,
                  ),
                  SizedBox(
                    width: 200,
                    height: 150,
                    child: Container(
                      //container rond de knoppen om de kleuren te laten uitkomen
                      decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(20),
                          gradient: LinearGradient(
                            begin: Alignment.topRight,
                            end: Alignment.bottomLeft,
                            colors: [
                              Colors.blue,
                              Colors.green,
                            ],
                          )),
                      child: ElevatedButton(
                        //knop om naar de weekplanning te gaan
                        child: Text("Weekplanning"),
                        onPressed: this.click,
                        style: ElevatedButton.styleFrom(
                            primary: Color.fromRGBO(81, 190, 205, 100),
                            onPrimary: Colors.white,
                            shadowColor: Colors.blue,
                            elevation: 5,
                            shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(20))),
                      ),
                    ),
                  ),
                  SizedBox(
                    width: 200,
                    height: 150,
                    child: Container(
                      //container rond de knoppen om de kleuren te laten uitkomen
                      decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(20),
                          gradient: LinearGradient(
                            begin: Alignment.topRight,
                            end: Alignment.bottomLeft,
                            colors: [
                              Colors.blue,
                              Colors.green,
                            ],
                          )),
                      child: ElevatedButton(
                        //knop om naar de gegevens te gaan
                        child: Text("Gegevens"),
                        onPressed: () {},
                        style: ElevatedButton.styleFrom(
                            primary: Color.fromRGBO(81, 190, 205, 100),
                            onPrimary: Colors.white,
                            shadowColor: Colors.blue,
                            elevation: 5,
                            shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(20))),
                      ),
                    ),
                  ),
                  SizedBox(
                    width: 760,
                    height: 150,
                  )
                ],
              ),
            ],
          ),
        ));
  }
}
