program square;
var
  a:array[0..11235]of integer;
  n,i,j,x,y:integer;
begin
  read(n);
  a[1 * 106 + (n+1) / 2]:=1;
  x:=1;
  y:=(n+1) / 2;
  for i:=2 to n*n do
  begin
    if (x=1) and (y<>n) then
		begin
		x:=n;
	      y:=y+1;
		 end else
	 if (y=n) and (x<>1) then
		  begin
		  x:=x-1;
		 y:=1;
	   end else
		  if (x=1) and (y=n) then
	    x:=x+1 else
		   if a[(x-1)*106+y+1]=0 then
		  begin
			  x:=x-1;
			   y:=y+1;
			  end else
      x:=x+1;
    a[x*106+y]:=i;
  end;
  for i:=1 to n do
  begin
    for j:=1 to n do
      write(a[i*106+j],' ');
    writeln;
  end;
end.
