
int asn1_do_lock(ASN1_VALUE **pval,int op,ASN1_ITEM *it)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  if ((it->itype == '\x01') || (uVar2 = 0, it->itype == '\x06')) {
    pvVar1 = it->funcs;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)((int)pvVar1 + 4) & 1;
      if (uVar2 != 0) {
        if (op == 0) {
          *(int *)(*pval + *(int *)((int)pvVar1 + 8)) = 1;
          return 1;
        }
        iVar3 = CRYPTO_add_lock((int *)(*pval + *(int *)((int)pvVar1 + 8)),op,
                                *(int *)((int)pvVar1 + 0xc),"tasn_utl.c",0x76);
        return iVar3;
      }
    }
  }
  return uVar2;
}

