
ulong bn_div_words(ulong h,ulong l,ulong d)

{
  ulong uVar1;
  
  uVar1 = __udivdi3(l,h,d,0);
  return uVar1;
}

