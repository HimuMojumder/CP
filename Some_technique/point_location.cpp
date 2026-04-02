/*
point location test

*/
 int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  int x=a*(d-f)+c*(f-b)+e*(b-d);
  if(x==0)cout<<"TOUCH"<<endl;
  else if(x>0)cout<<"LEFT"<<endl;
  else  cout<<"RIGHT"<<endl;
