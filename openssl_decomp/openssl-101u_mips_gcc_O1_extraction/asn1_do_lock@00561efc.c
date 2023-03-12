
int asn1_do_lock(ASN1_VALUE **pval,int op,ASN1_ITEM *it)

{
  uint uVar1;
  void *pvVar2;
  
  if (((it->itype == '\x01') || (it->itype == '\x06')) &&
     (pvVar2 = it->funcs, pvVar2 != (void *)0x0)) {
    uVar1 = *(uint *)((int)pvVar2 + 4) & 1;
    if (uVar1 != 0) {
      if (op == 0) {
        *(undefined4 *)(*pval + *(int *)((int)pvVar2 + 8)) = 1;
        return 1;
      }
      uVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                        (*pval + *(int *)((int)pvVar2 + 8),op,*(undefined4 *)((int)pvVar2 + 0xc),
                         "tasn_utl.c",0x76);
    }
    return uVar1;
  }
  return 0;
}

