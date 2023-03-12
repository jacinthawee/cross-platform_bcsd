
size_t EC_get_builtin_curves(EC_builtin_curve *r,size_t nitems)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (nitems != 0 && r != (EC_builtin_curve *)0x0) {
    uVar1 = 0;
    if (0x42 < nitems) {
      nitems = 0x43;
    }
    puVar3 = &curve_list;
    uVar2 = uVar1;
    do {
      uVar4 = *puVar3;
      uVar1 = uVar1 + 1;
      uVar5 = puVar3[3];
      puVar3 = puVar3 + 4;
      *(undefined4 *)((int)&r->nid + uVar2) = uVar4;
      *(undefined4 *)((int)&r->comment + uVar2) = uVar5;
      uVar2 = uVar2 + 8;
    } while (uVar1 < nitems);
    return 0x43;
  }
  return 0x43;
}

