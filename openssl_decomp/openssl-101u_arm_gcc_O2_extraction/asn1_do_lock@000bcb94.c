
int asn1_do_lock(ASN1_VALUE **pval,int op,ASN1_ITEM *it)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  
  if (it->itype != '\x06' && it->itype != '\x01') {
    return 0;
  }
  pvVar3 = it->funcs;
  if (pvVar3 != (void *)0x0) {
    uVar1 = *(uint *)((int)pvVar3 + 4) & 1;
    if (uVar1 != 0) {
      if (op != 0) {
        iVar2 = CRYPTO_add_lock((int *)(*pval + *(int *)((int)pvVar3 + 8)),op,
                                *(int *)((int)pvVar3 + 0xc),"tasn_utl.c",0x76);
        return iVar2;
      }
      uVar1 = 1;
      *(undefined4 *)(*pval + *(int *)((int)pvVar3 + 8)) = 1;
    }
    return uVar1;
  }
  return 0;
}

