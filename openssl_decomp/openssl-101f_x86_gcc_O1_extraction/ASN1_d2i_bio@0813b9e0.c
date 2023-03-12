
/* WARNING: Removing unreachable block (ram,0x0813ba36) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ASN1_d2i_bio(xnew *xnew,undefined1 *d2i,BIO *in,void **x)

{
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = asn1_d2i_read_bio_constprop_0();
  if (iVar1 < 0) {
    pvVar2 = (void *)0x0;
  }
  else {
    local_14 = _DAT_00000004;
    pvVar2 = (void *)(*(code *)d2i)(x,&local_14,iVar1);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar2;
}

