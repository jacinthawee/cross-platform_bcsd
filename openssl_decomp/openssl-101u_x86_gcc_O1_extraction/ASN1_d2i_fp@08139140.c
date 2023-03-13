
/* WARNING: Removing unreachable block (ram,0x081391c3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ASN1_d2i_fp(xnew *xnew,undefined1 *d2i,FILE *in,void **x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4c);
    pvVar2 = (void *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,in);
    iVar1 = asn1_d2i_read_bio_constprop_0();
    if (iVar1 < 0) {
      pvVar2 = (void *)0x0;
    }
    else {
      local_24 = _DAT_00000004;
      pvVar2 = (void *)(*(code *)d2i)(x,&local_24,iVar1);
    }
    BIO_free(bp);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar2;
}

