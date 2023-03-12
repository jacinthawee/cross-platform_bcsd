
int sk_find(_STACK *st,void *data)

{
  void *pvVar1;
  char *pcVar2;
  char **ppcVar3;
  __compar_fn_t __compar;
  void *local_14;
  
  if (st != (_STACK *)0x0) {
    __compar = (__compar_fn_t)st->comp;
    if (__compar == (__compar_fn_t)0x0) {
      if (0 < (int)(__compar_fn_t)st->num) {
        ppcVar3 = st->data;
        pcVar2 = *ppcVar3;
        while( true ) {
          if ((char *)data == pcVar2) {
            return (int)__compar;
          }
          __compar = __compar + 1;
          if (__compar == (__compar_fn_t)st->num) break;
          ppcVar3 = ppcVar3 + 1;
          pcVar2 = *ppcVar3;
        }
        return -1;
      }
    }
    else {
      local_14 = data;
      if (st->sorted == 0) {
        qsort(st->data,st->num,4,__compar);
        st->sorted = 1;
      }
      if ((local_14 != (void *)0x0) &&
         (pvVar1 = OBJ_bsearch_ex_(&local_14,st->data,st->num,4,(cmp *)st->comp,2),
         pvVar1 != (void *)0x0)) {
        return (int)pvVar1 - (int)st->data >> 2;
      }
    }
  }
  return -1;
}

