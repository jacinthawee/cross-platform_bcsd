
void sk_zero(_STACK *st)

{
  undefined4 in_a3;
  
  if ((st != (_STACK *)0x0) && (0 < st->num)) {
    (*(code *)PTR_memset_006a99f4)(st->data,0,st->num << 2,in_a3,&_gp);
    st->num = 0;
  }
  return;
}

