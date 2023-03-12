
void sk_sort(_STACK *st)

{
  if ((st != (_STACK *)0x0) && (st->sorted == 0)) {
    (*(code *)PTR_qsort_006aaa94)(st->data,st->num,4,st->comp,&_gp);
    st->sorted = 1;
    return;
  }
  return;
}

