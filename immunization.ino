String immunization(int week) {
String mp3audios = {""};  // Array to store played audio numbers for each week (1-40)

  if (week == 1) {
    Serial.println("Playing Week 1 Audios...");
     mp3_play(7025);  // hfta phla
    delay(3000);
     mp3audios += "_";
    mp3audios += 7025;
   mp3_play(7026);  //grbvstha shuru hoti h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7026;
   mp3_play(7027);  // niymt rup se .....krwae
    delay(8000); 
    mp3audios += "_";
    mp3audios += 7027;
   mp3_play(7028);   // apne dhyn rkhe....zimmedari h
    delay(5000); 
    mp3audios += "_";
    mp3audios += 7028;
   mp3_play(7029);  // apne garvdhrn k baad ....soch skti h
    delay(7000); 
    mp3audios += "_";
    mp3audios += 7029;
   mp3_play(7030);  // smoking etc  sevan na kre.....
    delay(9000); 
    mp3audios += "_";
    mp3audios += 7030;
  }

   else if (week == 2) {
    Serial.println("Playing Week 2 Audios...");
     mp3_play(7031);//hfta 2......charan h...rkhe
    delay(4000);
    mp3audios += "_";
    mp3audios += 7031;
   mp3_play(7032);//hfta 2......charan h...rkhe
    delay(8000);
    mp3audios += "_";
    mp3audios += 7032;
   mp3_play(7033);//apni sharirik swacta....ni hogi
    delay(5000);
    mp3audios += "_";
    mp3audios += 7033;
   mp3_play(7034);//sbzi dhokr khae
    delay(9000);
    mp3audios += "_";
    mp3audios += 7034;
   mp3_play(7035);//grbdharan k baare m.....tyar h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7035;
   mp3_play(7036);//agla bccha ......3 sal ka na hojae 
    delay(8000);
    mp3audios += "_";
    mp3audios += 7036;
  }

   else if (week == 3) {
    Serial.println("Playing Week 3 Audios...");
    mp3_play(7037);//hfta 3..........pita pr nirbhr krta h 
    delay(3000);
    mp3audios += "_";
    mp3audios += 7037;
   mp3_play(7038);//hfta 3..........pita pr nirbhr krta h 
    delay(7000);
    mp3audios += "_";
    mp3audios += 7038;
   mp3_play(7039);//chulhe k dhue...........pryog kren
    delay(7000);
    mp3audios += "_";
    mp3audios += 7039;
   mp3_play(7040);//pryapt mtrA......avshekta h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7040;
   mp3_play(7041);//ghr ko hmesha.......hwadar rke
    delay(5000);
    mp3audios += "_";
    mp3audios += 7041;
   mp3_play(7042);//ydi ji mchlana......deri na kre
    delay(10000);
    mp3audios += "_";
    mp3audios += 7042;
  }

   else if (week == 4) {
    Serial.println("Playing Week 4 Audios...");
     mp3_play(7043);//hfta 4.......grbdarn kr chuki h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7043;
   mp3_play(7044);//hfta 4.......grbdarn kr chuki h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7044;
   mp3_play(7045);//swsthkenrd m dctr......pushthi kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7045;
   mp3_play(7046);//khul brtn......nasht hojate h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7046;
   mp3_play(7047);//pine khane k lye.....saaf pani .....kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7047;
   mp3_play(7048);//mitti m nange pao......keede hojte h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7048;
  }

   else if (week == 5) {
    Serial.println("Playing Week 5 Audios...");
     mp3_play(7049);//hfta 5 bdhai ho........ma BNNE WALI H
    delay(4000);
    mp3audios += "_";
    mp3audios += 7049;
   mp3_play(7050);//hfta 5 bdhai ho........ma BNNE WALI H
    delay(8000);
    mp3audios += "_";
    mp3audios += 7050;
   mp3_play(7051);//ghr k nikt......pnjikrn krae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7051;
   mp3_play(7052);//sntulit ahar.........maatra m ho
    delay(5000);
    mp3audios += "_";
    mp3audios += 7052;
   mp3_play(7053);//ji mchlane se......turnt kch khae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7053;
   mp3_play(7054);//koshish kre heavy wt na uthae
    delay(4000);
    mp3audios += "_";
    mp3audios += 7054;
  }
   else if (week == 6) {
    Serial.println("Playing Week 6 Audios...");
     mp3_play(7055);//hfta 6.........shuru ho chuki h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7055;
   mp3_play(7056);//hfta 6.........shuru ho chuki h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7056;
   mp3_play(7057);//tetns ka....injection lgwae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7057;
   mp3_play(7058);//iron ahar le.......dlya aadi
    delay(3000);
    mp3audios += "_";
    mp3audios += 7058;
   mp3_play(7059);//din m thoda thida......5-6 baar khae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7059;
   mp3_play(7060);//bidhi .......hanikark h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7060;
  }
   else if (week == 7) {
    Serial.println("Playing Week 7 Audios...");
    mp3_play(7061);//hfta 7 ab shishu k.....viksit hone lge h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7061;
   mp3_play(7062);//hfta 7 ab shishu k.....viksit hone lge h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7062;
   mp3_play(7063);//iron , policacid.......uplabdh h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7063;
   mp3_play(7064);//din m ek ......avashay khae
    delay(9000);
    mp3audios += "_";
    mp3audios += 7064;
   mp3_play(7065);//ghr k kaam....na ghbrae 
    delay(8000);
    mp3audios += "_";
    mp3audios += 7065;
   mp3_play(7066);//pshan k sth chsi.......bche
    delay(4000);
    mp3audios += "_";
    mp3audios += 7066;
  }
   else if (week == 8) {
    Serial.println("Playing Week 8 Audios...");
     mp3_play(7067);//hfta 8 abb aapke shuishu....viksit ungli h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7067;
   mp3_play(7068);//hfta 8 abb aapke shuishu....viksit ungli h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7068;
   mp3_play(7069);//kch dwae........salah pr koi dwa na le
    delay(7000);
    mp3audios += "_";
    mp3audios += 7069;
   mp3_play(7070);//apne shishu ke.......poshtik bhojan kahe
    delay(11000);
    mp3audios += "_";
    mp3audios += 7070;
   mp3_play(7071);//koshish kre duin me....aram kre
    delay(6000);
    mp3audios += "_";
    mp3audios += 7071;
   mp3_play(7072);//lmbe smaey........bche
    delay(5000);
    mp3audios += "_";
    mp3audios += 7072;
  }
   else if (week == 9) {
    Serial.println("Playing Week 9 Audios...");
      mp3_play(7073);//hfta 9 sir ka vikas...horha h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7073;
   mp3_play(7074);//hfta 9 sir ka vikas...horha h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7074;
   mp3_play(7075);//iron or polic acid .......uplabdh h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7075;
   mp3_play(7076);//khane me hmesha iodine.....zruri h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7076;
   mp3_play(7077);//pet mu jln......msal9o se bche
    delay(8000);
    mp3audios += "_";
    mp3audios += 7077;
   mp3_play(7078);//koshish kre heavy wt na uthae
    delay(4000);
    mp3audios += "_";
    mp3audios += 7078;
  }
   else if (week == 10) {
    Serial.println("Playing Week 10 Audios...");
     mp3_play(7079);//hfta 10 aapka nanha shishu....hinle lga h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7079;
   mp3_play(7080);//hfta 10 aapka nanha shishu....hinle lga h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7080;
   mp3_play(7081);//tetnus ka dusra injectn...
    delay(7000);
    mp3audios += "_";
    mp3audios += 7081;
   mp3_play(7082);//khane ke baad gurh.....bchata h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7082;
   mp3_play(7083);//koshuiash kre ....night ko 8 hrs ....nind le
    delay(5000);
    mp3audios += "_";
    mp3audios += 7083;
   mp3_play(7084);//bhojan k sth chai se bche
    delay(4000);
    mp3audios += "_";
    mp3audios += 7084;
  }
   else if (week == 11) {
    Serial.println("Playing Week 11 Audios...");
     mp3_play(7085);//hfta 11 ab aapka nanha ...khan ek swad....phchan skta h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7085;
   mp3_play(7086);//hfta 11 ab aapka nanha ...khan ek swad....phchan skta h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7086;
   mp3_play(7087);//hiv .....anemia jaanch krwae
    delay(11000);
    mp3audios += "_";
    mp3audios += 7087;
   mp3_play(7088);//cough se bchne ke ......sevan krte rhe
    delay(5000);
    mp3audios += "_";
    mp3audios += 7088;
   mp3_play(7089);//koshish kre kaam k bich m thoda arm
    delay(6000);
    mp3audios += "_";
    mp3audios += 7089;
   mp3_play(7090);//pet m jln s bchne.......sevan se bche
    delay(8000);
    mp3audios += "_";
    mp3audios += 7090;
  }
   else if (week == 12) {
    Serial.println("Playing Week 12 Audios...");
    mp3_play(7091);//hfta 12  ab aapka .....drd .....jhtke se bche
    delay(3000);
    mp3audios += "_";
    mp3audios += 7091;
   mp3_play(7092);//hfta 12  ab aapka .....drd .....jhtke se bche
    delay(9000);
    mp3audios += "_";
    mp3audios += 7092;
   mp3_play(7093);//swastkendr m bp anemia jaanch krae 
    delay(9000);
    mp3audios += "_";
    mp3audios += 7093;
   mp3_play(7094);//pryapt vitm pane chikoo.......sitaaphal khae
    delay(7000);
    mp3audios += "_";
    mp3audios += 7094;
   mp3_play(7095);//bcche k jn k samy.........jma krna shuru kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7095;
   mp3_play(7096);//koshish kre heavy wt na uthae
    delay(4000);
    mp3audios += "_";
    mp3audios += 7096;
  }
   else if (week == 13) {
    Serial.println("Playing Week 13 Audios...");
   mp3_play(7097);//hfta 13 ab aapka .......angutha chusne lga......sahayk hoga
    delay(10000);
    mp3audios += "_";
    mp3audios += 7097;
   mp3_play(7098);//ydi peshab m jln.....btae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7098;
   mp3_play(7099);//iron ykt ahar le.......chiwrha aadi
    delay(6000);
    mp3audios += "_";
    mp3audios += 7099;
   mp3_play(7100);//din me thod thda bhojn 5-6 ....khae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7100;
   mp3_play(7101);//peshab hone ki icha ......turnt jae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7101;
  }
   else if (week == 14) {
    Serial.println("Playing Week 14 Audios...");
     mp3_play(7102);//hfta 14 ab .......haddi  mzbut horhi h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7102;
   mp3_play(7103);//hfta 14 ab .......haddi  mzbut horhi h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7103;
   mp3_play(7104);//mithe khane ki icha......keede hoskte h
    delay(12000);
    mp3audios += "_";
    mp3audios += 7104;
   mp3_play(7105);//shishu ki haddiyo.......pattedar sbziya khae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7105;
   mp3_play(7106);//koshish kre din m kaam k bich 2 ghnte aram kre
    delay(7000);
    mp3audios += "_";
    mp3audios += 7106;
   mp3_play(7107);//bhojn k sth chai .....bche
    delay(4000);
    mp3audios += "_";
    mp3audios += 7107;
  }
   else if (week == 15) {
    Serial.println("Playing Week 15 Audios...");
    mp3_play(7108);//hfta 15 ab .......nakhun baalo ka vikas horha h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7108;
   mp3_play(7109);//hfta 15 ab .......nakhun baalo ka vikas horha h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7109;
   mp3_play(7110);//khasre k lkshn.......lmbe smy tk srdrd
    delay(6000);
    mp3audios += "_";
    mp3audios += 7110;
   mp3_play(7111);//din m km s km ......hri sbzi khae
    delay(13000);
    mp3audios += "_";
    mp3audios += 7111;
   mp3_play(7112);//ghhr k hlke kaam......na ghbrae 
    delay(8000);
    mp3audios += "_";
    mp3audios += 7112;
   mp3_play(7113);//subah uthne k bad khali pet kbhi  na rhe
    delay(5000);
    mp3audios += "_";
    mp3audios += 7113;
  }
   else if (week == 16) {
    Serial.println("Playing Week 16 Audios...");
     mp3_play(7114);//hfta 16 ab aapke  shishu...naal la vikas ....hogya h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7114;
   mp3_play(7115);//hfta 16 ab aapke  shishu...naal la vikas ....hogya h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7115;
   mp3_play(7116);//ydi baar baar pyas lge......hoskta h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7116;
   mp3_play(7117);//protein yukt chize......anda zrur khae
    delay(10000);
    mp3audios += "_";
    mp3audios += 7117;
   mp3_play(7118);//din m thda thda bhojn 5-6 baar khae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7118;
   mp3_play(7119);//grbh m ldaka ldki ...apradh h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7119;
  }
   else if (week == 17) {
    Serial.println("Playing Week 17 Audios...");
     mp3_play(7120);//hfta 17 aapka nanha shishu....ghumne lga h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7120;
   mp3_play(7121);//hfta 17 aapka nanha shishu....ghumne lga h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7121;
   mp3_play(7122);//iron or polic acid ......uplabdh h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7122;
   mp3_play(7123);//ironyukt ahar ..........phlya aaadi
    delay(9000);
    mp3audios += "_";
    mp3audios += 7123;
   mp3_play(7124);//hmesha iodine yukt nmk ....khride
    delay(5000);
    mp3audios += "_";
    mp3audios += 7124;
   mp3_play(7125);//koshish kre heavy wt na uthae
    delay(5000);
    mp3audios += "_";
    mp3audios += 7125;
  }
   else if (week == 18) {
    Serial.println("Playing Week 18 Audios...");
     mp3_play(7126);//hfta 18 apne pati ko ......hrkt mhsus krwae
    delay(4000);
    mp3audios += "_";
    mp3audios += 7126;
   mp3_play(7127);//hfta 18 apne pati ko ......hrkt mhsus krwae
    delay(5000);
    mp3audios += "_";
    mp3audios += 7127;
   mp3_play(7128);//ydi aap chehre......sujan......dctr ko dikhae
    delay(12000);
    mp3audios += "_";
    mp3audios += 7128;
   mp3_play(7129);//cough se bchne k lye.....gajar aadi.....sevan kre
    delay(9000);
    mp3audios += "_";
    mp3audios += 7129;
   mp3_play(7130);//lmbe sme tk kaam.......bche
    delay(6000);
    mp3audios += "_";
    mp3audios += 7130;
   mp3_play(7131);//bidhi cigrete shrb......hanikark h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7131;
  }
   else if (week == 19) {
    Serial.println("Playing Week 19 Audios...");
    mp3_play(7132);//hfta 19 aapka shishu....ang,jese ,dil,dimg,gurde....vikas ...h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7132;
   mp3_play(7133);//hfta 19 aapka shishu....ang,jese ,dil,dimg,gurde....vikas ...h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7133;
   mp3_play(7134);//swastkendr m bp ...anaemia....krwae
    delay(10000);
    mp3audios += "_";
    mp3audios += 7134;
   mp3_play(7135);//shishu ki hddiyo k......pattedar sbziya khae
    delay(7000);
    mp3audios += "_";
    mp3audios += 7135;
   mp3_play(7136);//dheele aramdayk kpde phne
    delay(5000);
    mp3audios += "_";
    mp3audios += 7136;
   mp3_play(7137);//peshab ki icha hone pr .....turnt jae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7137;
  }
   else if (week == 20) {
    Serial.println("Playing Week 20 Audios...");
     mp3_play(7138);//hfta 20 shishu.......hrke se jaangne sone ka smay pehchan skti h 
    delay(4000);
    mp3audios += "_";
    mp3audios += 7138;
   mp3_play(7139);//hfta 20 shishu.......hrke se jaangne sone ka smay pehchan skti h 
    delay(8000);
    mp3audios += "_";
    mp3audios += 7139;
   mp3_play(7140);//ydi shishu ki hrkt m koi bdlao therao .......dctr ko diake
    delay(7000);
    mp3audios += "_";
    mp3audios += 7140;
   mp3_play(7141);//kabz pet m jln.....pani pie
    delay(9000);
    mp3audios += "_";
    mp3audios += 7141;
   mp3_play(7142);//bcche ke jnm k smy.....jma krna shuru kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7142;
   mp3_play(7143);//koshish kre hvy wt na uthae
    delay(5000);
    mp3audios += "_";
    mp3audios += 7143;
  }
   else if (week == 21) {
    Serial.println("Playing Week 21 Audios...");
     mp3_play(7144);//hfta 21 ab aap  shishu....apki awaz  sun  skta h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7144;
   mp3_play(7145);//hfta 21 ab aap  shishu....apki awaz  sun  skta h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7145;
   mp3_play(7146);//hiv ...anemia.....jaanch karae
    delay(7000);
    mp3audios += "_";
    mp3audios += 7146;
   mp3_play(7147);//din m km s km ......daal avshya khae
    delay(5000);
    mp3audios += "_";
    mp3audios += 7147;
   mp3_play(7148);//mn ko shant or.......sngeet sune
    delay(6000);
    mp3audios += "_";
    mp3audios += 7148;
   mp3_play(7149);//grbhti mhila aas pass.......dar skta h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7149;
  }
   else if (week == 22) {
    Serial.println("Playing Week 22 Audios...");
    mp3_play(7150);//hfta 22 aapka  shishu....chukr mhsus krskta h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7150;
   mp3_play(7151);//hfta 22 aapka  shishu....chukr mhsus krskta h
    delay(5000);
    mp3audios += "_";
    mp3audios += 7151;
   mp3_play(7152);//mitti khane ki icha.......keede ......nuksan hoskta h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7152;
   mp3_play(7153);//apne bhojn ki mtra.......avshkta h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7153;
   mp3_play(7154);//din m thda thda bhojan 5-6 ....khae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7154;
   mp3_play(7155);//pet m jln s ........msalo ke sevn ...bche
    delay(8000);
    mp3audios += "_";
    mp3audios += 7155;
  }
   else if (week == 23) {
    Serial.println("Playing Week 23 Audios...");
    mp3_play(7156);//hfta 23 aap shishu....per marna mhsus krskti h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7156;
   mp3_play(7157);//hfta 23 aap shishu....per marna mhsus krskti h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7157;
   mp3_play(7158);//khsre k lkshn.......hatho pr sujan
    delay(8000);
    mp3audios += "_";
    mp3audios += 7158;
   mp3_play(7159);//ironyukt ahar......phlya aadi
    delay(15000);
    mp3audios += "_";
    mp3audios += 7159;
   mp3_play(7160);//bcche k jnm k......pese jma....kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7160;
   mp3_play(7161);//tno m bharipn......tyar horha h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7161;
  }
   else if (week == 24) {
    Serial.println("Playing Week 24 Audios...");
     mp3_play(7162);//hfta 24 hmesha khush rhye......anand lijye
    delay(4000);
    mp3audios += "_";
    mp3audios += 7162;
   mp3_play(7163);//hfta 24 hmesha khush rhye......anand lijye
    delay(6000);
    mp3audios += "_";
    mp3audios += 7163;
   mp3_play(7164);//swaskendra m .....anaemia....krae
    delay(7000);
    mp3audios += "_";
    mp3audios += 7164;
   mp3_play(7165);//khanij vtmn ......mtra m khae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7165;
   mp3_play(7166);//koshish kre ......2 ghnte aram ...kre
    delay(7000);
    mp3audios += "_";
    mp3audios += 7166;
   mp3_play(7167);//grbh m ldka ldki,.....apradh h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7167;
    }
   else if (week == 25) {
    Serial.println("Playing Week 25 Audios...");
     mp3_play(7168);//hfta 25 aapka  shishu......ma pita ki awaz....phchan skta h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7168;
   mp3_play(7169);//hfta 25 aapka  shishu......ma pita ki awaz....phchan skta h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7169;
   mp3_play(7170);//iron or policacis.....uplabhd h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7170;
   mp3_play(7171);//protein yukt chize........ankurit daale...anda khae
    delay(9000);
    mp3audios += "_";
    mp3audios += 7171;
   mp3_play(7172);//hmesha iodine yukt.....khride
    delay(5000);
    mp3audios += "_";
    mp3audios += 7172;
   mp3_play(7173);//apne shishu k sth pyarbhri.......yaad....rehskta h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7173;
  }
   else if (week == 26) {
    Serial.println("Playing Week 26 Audios...");
    mp3_play(7174);//hfta 26 aapne shishu ki surksha........kre
    delay(4000);
    mp3audios += "_";
    mp3audios += 7174;
   mp3_play(7175);//hfta 26 aapne shishu ki surksha........kre
    delay(7000);
    mp3audios += "_";
    mp3audios += 7175;
   mp3_play(7176);//ydi baar baar pyas.......hoskta h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7176;
   mp3_play(7177);//kbz s bchne..........gajar aadi....rhe
    delay(10000);
    mp3audios += "_";
    mp3audios += 7177;
   mp3_play(7178);//dheele .......phne
    delay(4000);
    mp3audios += "_";
    mp3audios += 7178;
   mp3_play(7179);//koshish kre....khde rhe
    delay(7000);
    mp3audios += "_";
    mp3audios += 7179;
  }
   else if (week == 27) {
    Serial.println("Playing Week 27 Audios...");
     mp3_play(7180);//hfta 27 aapke shishu....spne dek skta h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7180;
   mp3_play(7181);//hfta 27 aapke shishu....spne dek skta h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7181;
   mp3_play(7182);//ydi aap chere.......dct ko dikae
    delay(12000);
    mp3audios += "_";
    mp3audios += 7182;
   mp3_play(7183);//shishu ki hddiyo.......pattedar sbzi khae
    delay(9000);
    mp3audios += "_";
    mp3audios += 7183;
   mp3_play(7184);//dhyan rkhe....krvt....soe
    delay(5000);
    mp3audios += "_";
    mp3audios += 7184;
   mp3_play(7185);//jhgrhe tnav....dur rhe
    delay(4000);
    mp3audios += "_";
    mp3audios += 7185;
  } 
   else if (week == 28) {
    Serial.println("Playing Week 28 Audios...");
    mp3_play(7186);//hfta 28 aapka shishu....andhere ujale....lga h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7186;
   mp3_play(7187);//hfta 28 aapka shishu....andhere ujale....lga h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7187;
   mp3_play(7188);//kch dwae ....nuiksn......dwa na le
    delay(8000);
    mp3audios += "_";
    mp3audios += 7188;
   mp3_play(7189);//ironyukt ahar........phlya aaadi
    delay(13000);
    mp3audios += "_";
    mp3audios += 7189;
   mp3_play(7190);//ghr k hlke........ghbrae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7190;
   mp3_play(7191);//pet m jln .......sevn s bche
    delay(8000);
    mp3audios += "_";
    mp3audios += 7191;
  }  
   else if (week == 29) {
    Serial.println("Playing Week 29 Audios...");
     mp3_play(7192);//hfta 29 apne shishu....ma ka pila.....avshek h
    delay(4000);
    mp3audios += "_";
    mp3audios +=7192;
   mp3_play(7193);//hfta 29 apne shishu....ma ka pila.....avshek h
    delay(11000);
    mp3audios += "_";
    mp3audios +=7193;
   mp3_play(7194);//ydi ...sujan srdrd....dikhae
    delay(10000);
    mp3audios += "_";
    mp3audios +=7194;
   mp3_play(7195);//prtein ......doodh anda khae
    delay(10000);
    mp3audios += "_";
    mp3audios +=7195;
   mp3_play(7196);//bcche ko.....pti k sth chrcha kre
    delay(6000);
    mp3audios += "_";
    mp3audios +=7196;
   mp3_play(7197);//koshish kre ......khde rhe
    delay(6000);
    mp3audios += "_";
    mp3audios +=7197;    
  }
    
   else if (week == 30) {
    Serial.println("Playing Week 30 Audios...");
     mp3_play(7198);//hfta 30 dhyan rkhe....gae....aveshk h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7198;
   mp3_play(7199);//hfta 30 dhyan rkhe....gae....aveshk h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7199;
   mp3_play(7200);//mitti ...icha.....keede....phuchskta h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7200;
   mp3_play(7201);//atirikt bhjn......zrurt h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7201;
   mp3_play(7202);//bcche k jnm....pese jma..kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7202;
   mp3_play(7203);//bidhi...shrb.....hnikrk h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7203;
  } 
   else if (week == 31) {
    Serial.println("Playing Week 31 Audios...");
     mp3_play(7204);//hfta 31 pet m pirha.....snket h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7204;
   mp3_play(7205);//hfta 31 pet m pirha.....snket h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7205;
   mp3_play(7206);//khsre k.....srdrd,sujn
    delay(8000);
    mp3audios += "_";
    mp3audios += 7206;
   mp3_play(7207);//khne m soyaben......le
    delay(15000);
    mp3audios += "_";
    mp3audios += 7207;
   mp3_play(7208);//ghr pr....5 chize......saaf ....sheet
    delay(16000);
    mp3audios += "_";
    mp3audios += 7208;
   mp3_play(7209);//koshish kre.......na uthae
    delay(5000);
    mp3audios += "_";
    mp3audios += 7209;
  }  
   else if (week == 32) {
    Serial.println("Playing Week 32 Audios...");
     mp3_play(7210);//hfta 32 nrvjaat shishu.......lpate
    delay(4000);
    mp3audios += "_";
    mp3audios += 7210;
   mp3_play(7211);//hfta 32 nrvjaat shishu.......lpate
    delay(10000);
    mp3audios += "_";
    mp3audios += 7211;
   mp3_play(7212);//ydi shishu.....therao...dikae
    delay(13000);
    mp3audios += "_";
    mp3audios += 7212;
   mp3_play(7213);//shishu ki hddiyo......calcium...khae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7213;
   mp3_play(7214);//bcche k jnm...  chrcha ....hota h
    delay(12000);
    mp3audios += "_";
    mp3audios += 7214;
   mp3_play(7215);//peet k bl..... hojata h
    delay(6000);
    mp3audios += "_";
    mp3audios += 7215;
  }  
   else if (week == 33) {
    Serial.println("Playing Week 33 Audios...");
    mp3_play(7216);//hfta 33 ab shishu.......niche.....hoskti h
    delay(3000);
    mp3audios += "_";
    mp3audios += 7216;
   mp3_play(7217);//hfta 33 ab shishu.......niche.....hoskti h
    delay(8000);
    mp3audios += "_";
    mp3audios += 7217;
   mp3_play(7218);//iron or polic........uplbhd h
    delay(11000);
    mp3audios += "_";
    mp3audios += 7218;
   mp3_play(7219);//kbz s .......gjr...rhe
    delay(9000);
    mp3audios += "_";
    mp3audios += 7219;
   mp3_play(7220);//aasha didi.......le
    delay(7000);
    mp3audios += "_";
    mp3audios += 7220;
   mp3_play(7221);//lmbe smy.....bche
    delay(5000);
    mp3audios += "_";
    mp3audios += 7221;
  }
   else if (week == 34) {
    Serial.println("Playing Week 34 Audios...");
    mp3_play(7222);//hfta 34 ......shuru krde
    delay(3000);
    mp3audios += "_";
    mp3audios += 7222;
   mp3_play(7223);//hfta 34 ......shuru krde
    delay(7000);
    mp3audios += "_";
    mp3audios += 7223;
   mp3_play(7224);//swstkendr bp.....krae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7224;
   mp3_play(7225);//ironyukt ahar....phlya aadi
    delay(7000);
    mp3audios += "_";
    mp3audios += 7225;
   mp3_play(7226);//asptl shi smy......krke rkhe
    delay(10000);
    mp3audios += "_";
    mp3audios += 7226;
   mp3_play(7227);//pet m jln......msalo...bche
    delay(8000);
    mp3audios += "_";
    mp3audios += 7227;
  } 
   else if (week == 35) {
    Serial.println("Playing Week 35 Audios...");
     mp3_play(7228);//hfta 35 .....dekhbhal kre
    delay(4000);
    mp3audios += "_";
    mp3audios += 7228;
   mp3_play(7229);//hfta 35 .....dekhbhal kre
    delay(11000);
    mp3audios += "_";
    mp3audios += 7229;
   mp3_play(7230);//khsre k ........srdrd sujan 
    delay(8000);
    mp3audios += "_";
    mp3audios += 7230;
   mp3_play(7231);//zyda matra .....bdhrha h....chye
    delay(14000);
    mp3audios += "_";
    mp3audios += 7231;
   mp3_play(7232);//din me ....5-6 baar khae
    delay(6000);
    mp3audios += "_";
    mp3audios += 7232;
   mp3_play(7233);//bidhu ,.....shrb......hnikrk h
    delay(10000);
    mp3audios += "_";
    mp3audios += 7233;
  }  
   else if (week == 36) {
    Serial.println("Playing Week 36 Audios...");
    mp3_play(7234);//hfta 36 ......jnkri le
    delay(3000);
    mp3audios += "_";
    mp3audios += 7234;
   mp3_play(7235);//hfta 36 ......jnkri le
    delay(8000);
    mp3audios += "_";
    mp3audios += 7235;
   mp3_play(7236);//ydi .....pyas.....hoaskta h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7236;
   mp3_play(7237);//din m .....dal....khae
    delay(10000);
    mp3audios += "_";
    mp3audios += 7237;
   mp3_play(7238);//is smy .... se chle
    delay(7000);
    mp3audios += "_";
    mp3audios += 7238;
   mp3_play(7239);//prtidin iron ,.......na bhule
    delay(7000);
    mp3audios += "_";
    mp3audios += 7239;
  } 
   else if (week == 37) {
    Serial.println("Playing Week 37 Audios...");
    mp3_play(7240);//hfta 37 .....operation.....bhtr hota h
    delay(4000);
    mp3audios += "_";
    mp3audios += 7240;
   mp3_play(7241);//hfta 37 .....operation.....bhtr hota h
    delay(9000);
    mp3audios += "_";
    mp3audios += 7241;
   mp3_play(7242);//ydi aap.......sujn....dikae
    delay(10000);
    mp3audios += "_";
    mp3audios += 7242;
   mp3_play(7243);//protein .........daale.....anda khae
    delay(11000);
    mp3audios += "_";
    mp3audios += 7243;
   mp3_play(7244);//bcche k jnm.....pese jma....kre
    delay(8000);
    mp3audios += "_";
    mp3audios += 7244;
   mp3_play(7245);//peet k bl......hojata h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7245;
  } 
   else if (week == 38) {
    Serial.println("Playing Week 38 Audios...");
     mp3_play(7246);//hfta 38 aapke swst......3 saal...antr rkhe
    delay(4000);
    mp3audios += "_";
    mp3audios += 7246;
   mp3_play(7247);//hfta 38 aapke swst......3 saal...antr rkhe
    delay(11000);
    mp3audios += "_";
    mp3audios += 7247;
   mp3_play(7248);//ydi shishu......therao....dikae
    delay(12000);
    mp3audios += "_";
    mp3audios += 7248;
   mp3_play(7249);//kbz s bchne ........gjr ....krte rhe
    delay(9000);
    mp3audios += "_";
    mp3audios += 7249;
   mp3_play(7250);//dheele ....phne
    delay(5000);
    mp3audios += "_";
    mp3audios += 7250;
   mp3_play(7251);//dcter s......na bhule
    delay(7000);
    mp3audios += "_";
    mp3audios += 7251;
  }  
  else if (week == 39) {
    Serial.println("Playing Week 39 Audios...");
     mp3_play(7252);//hfta 39... ....saman prem kre
    delay(4000);
    mp3audios += "_";
    mp3audios += 7252;
   mp3_play(7253);//hfta 39... ....saman prem kre
    delay(11000);
    mp3audios += "_";
    mp3audios += 7253;
   mp3_play(7254);//iron or polic acid.....uplabdh h
    delay(7000);
    mp3audios += "_";
    mp3audios += 7254;
   mp3_play(7255);//dhanij,vitm.....khae
    delay(8000);
    mp3audios += "_";
    mp3audios += 7255;
   mp3_play(7256);//asptl  jne.........tyr rkhe
    delay(9000);
    mp3audios += "_";
    mp3audios += 7256;
   mp3_play(7257);//jnm k baad......nal....suka rhke
    delay(9000);
    mp3audios += "_";
    mp3audios += 7257;
  }
  else if (week == 40) {
    Serial.println("Playing Week 40 Audios...");
     mp3_play(7258);//hfta 40 .....nzdik.....khila skegi
    delay(4000);
    mp3audios += "_";
    mp3audios += 7258;
   mp3_play(7259);//hfta 40 .....nzdik.....khila skegi
    delay(8000);
    mp3audios += "_";
    mp3audios += 7259;
   mp3_play(7260);//ydi aap......asptl jae
    delay(4000);
    mp3audios += "_";
    mp3audios += 7260;
   mp3_play(7261);//ironyukt......bhojn khae
    delay(12000);
    mp3audios += "_";
    mp3audios += 7261;
   mp3_play(7262);//prsn,tnavmukt.....baaten
    delay(9000);
    mp3audios += "_";
    mp3audios += 7262;
   mp3_play(7263);//jnm k ....1ghnte k andr....na bhule
    delay(9000);
    mp3audios += "_";
    mp3audios += 7263;

  }
  else {
    Serial.println("No audios for this week.");
  }
  
//      Serial.println(mp3audios);
//      sendDataToServer(mp3audios,week);
//     mp3_play(4342); //  nxt rfid card scan message 
//      delay(6000);

//     Serial.println(" Waiting 30 seconds for next RFID...");
//      unsigned long waitStart = millis();
//      while (millis() - waitStart < 30000) 
//       handleRFID(); 
//      if (newCardScanned) {
//      Serial.println(" New card detected within 30 seconds.");
//      return mp3audios;  // Skip thank you audio
//   }
//      delay(100); // avoid tight loop


//      Serial.println(" No new card detected. Playing thank you audio.");
//     mp3_play(4341); // 🔊 Thank you message
//      delay(10000);
 
//      Serial.println(" RFID scanning disabled after thank you message.");

//      while (true) {
//      delay(1000); // halt or idle indefinitely
// }
Serial.println(mp3audios);
sendDataToServer(mp3audios,week);
  
mp3_play(7023); // 🔊 "Thank you" message (optional)
delay(5000);
mp3_play(7024); // next rfid card 
delay(5000);
while (true) {
  handleRFID();  // This will process card, calculate age, play audio, etc.
  ageCal();
  delay(100);    // Prevent CPU overload
}

}
void showOfflineData() {
  if (!SPIFFS.exists(offlineFilePath)) {
    Serial.println("No offline data found.");
    return;
  }

  File file = SPIFFS.open(offlineFilePath, "r");
  if (!file) {
    Serial.println("Failed to open offline data file.");
    return;
  }

  Serial.println("===== Offline RFID Card Data =====");
    while (file.available()) {
    String line = file.readStringUntil('\n');
    Serial.println(line);  // Print the full line (one card’s data)
    delay(500);  // Optional delay to space output
  }
  Serial.println("==================================");
  file.close();
}
