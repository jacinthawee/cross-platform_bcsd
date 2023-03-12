
size_t EC_get_builtin_curves(EC_builtin_curve *r,size_t nitems)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  size_t sVar4;
  
  if ((r != (EC_builtin_curve *)0x0) && (nitems != 0)) {
    sVar4 = 0x43;
    if (nitems < 0x44) {
      sVar4 = nitems;
    }
    piVar1 = (int *)curve_list;
    do {
      piVar2 = piVar1 + 4;
      pcVar3 = (char *)piVar1[3];
      r->nid = *piVar1;
      r->comment = pcVar3;
      piVar1 = piVar2;
      r = r + 1;
    } while (piVar2 != (int *)(curve_list + sVar4 * 0x10));
  }
  return 0x43;
}

