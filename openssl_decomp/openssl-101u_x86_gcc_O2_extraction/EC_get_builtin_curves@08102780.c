
size_t EC_get_builtin_curves(EC_builtin_curve *r,size_t nitems)

{
  EC_builtin_curve *pEVar1;
  EC_builtin_curve *pEVar2;
  int *piVar3;
  
  if ((r != (EC_builtin_curve *)0x0) && (nitems != 0)) {
    if (0x43 < nitems) {
      nitems = 0x43;
    }
    pEVar1 = r;
    piVar3 = (int *)curve_list;
    do {
      pEVar2 = pEVar1 + 1;
      pEVar1->nid = *piVar3;
      pEVar1->comment = (char *)piVar3[3];
      pEVar1 = pEVar2;
      piVar3 = piVar3 + 4;
    } while (pEVar2 != r + nitems);
  }
  return 0x43;
}

