
int sk_find_ex(_STACK *st,void *data)

{
  void *pvVar1;
  __compar_fn_t __compar;
  int in_GS_OFFSET;
  void *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = data;
  if (st != (_STACK *)0x0) {
    __compar = (__compar_fn_t)st->comp;
    if (__compar == (__compar_fn_t)0x0) {
      if (0 < (int)(__compar_fn_t)st->num) {
        if ((char *)data == *st->data) {
          __compar = (__compar_fn_t)0x0;
        }
        else {
          do {
            __compar = __compar + 1;
            if ((__compar_fn_t)st->num == __compar) goto LAB_08121f7c;
          } while ((char *)data != st->data[(int)__compar]);
        }
        goto LAB_08121f2c;
      }
    }
    else {
      if (st->sorted == 0) {
        qsort(st->data,st->num,4,__compar);
        st->sorted = 1;
      }
      if (local_14 != (void *)0x0) {
        pvVar1 = OBJ_bsearch_ex_(&local_14,st->data,st->num,4,(cmp *)st->comp,1);
        if (pvVar1 != (void *)0x0) {
          __compar = (__compar_fn_t)((int)pvVar1 - (int)st->data >> 2);
          goto LAB_08121f2c;
        }
      }
    }
  }
LAB_08121f7c:
  __compar = (__compar_fn_t)0xffffffff;
LAB_08121f2c:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)__compar;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

