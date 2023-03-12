
int SMIME_text(BIO *in,BIO *out)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  bool bVar6;
  byte bVar7;
  char *local_102c [3];
  undefined local_1020 [4096];
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = (_STACK *)mime_parse_hdr();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd5,0xcf,"asn_mime.c",0x246);
    uVar3 = 0;
    goto LAB_081d098b;
  }
  local_102c[0] = "content-type";
  iVar1 = sk_find(st,local_102c);
  if (iVar1 < 0) {
LAB_081d0a00:
    ERR_put_error(0xd,0xd5,0xce,"asn_mime.c",0x24a);
  }
  else {
    pvVar2 = sk_value(st,iVar1);
    if (pvVar2 == (void *)0x0) goto LAB_081d0a00;
    bVar6 = *(char **)((int)pvVar2 + 4) == (char *)0x0;
    if (bVar6) goto LAB_081d0a00;
    iVar1 = 0xb;
    pcVar4 = *(char **)((int)pvVar2 + 4);
    pcVar5 = "text/plain";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (bVar6);
    if (bVar6) {
      sk_pop_free(st,mime_hdr_free);
      while( true ) {
        iVar1 = BIO_read(in,local_1020,0x1000);
        if (iVar1 < 1) break;
        BIO_write(out,local_1020,iVar1);
      }
      uVar3 = (uint)(iVar1 == 0);
      goto LAB_081d098b;
    }
    ERR_put_error(0xd,0xd5,0xcd,"asn_mime.c",0x24f);
    ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar2 + 4));
  }
  sk_pop_free(st,mime_hdr_free);
  uVar3 = 0;
LAB_081d098b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

