
void sk_sort(_STACK *st)

{
  if ((st != (_STACK *)0x0) && (st->sorted == 0)) {
    (*(code *)PTR_qsort_006a9988)(st->data,st->num,4,st->comp,&_gp);
    st->sorted = 1;
    return;
  }
  return;
}

