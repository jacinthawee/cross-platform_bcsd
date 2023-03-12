
int SMIME_text(BIO *in,BIO *out)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  char *local_1028 [3];
  undefined auStack_101c [4096];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  st = (_STACK *)mime_parse_hdr();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd5,0xcf,"asn_mime.c",0x238);
  }
  else {
    local_1028[0] = "content-type";
    iVar1 = sk_find(st,local_1028);
    if (((iVar1 < 0) || (pvVar2 = sk_value(st,iVar1), pvVar2 == (void *)0x0)) ||
       (*(char **)((int)pvVar2 + 4) == (char *)0x0)) {
      ERR_put_error(0xd,0xd5,0xce,"asn_mime.c",0x23c);
    }
    else {
      iVar1 = strcmp(*(char **)((int)pvVar2 + 4),"text/plain");
      if (iVar1 == 0) {
        sk_pop_free(st,mime_hdr_free + 1);
        while( true ) {
          iVar1 = BIO_read(in,auStack_101c,0x1000);
          if (iVar1 < 1) break;
          BIO_write(out,auStack_101c,iVar1);
        }
        if (iVar1 == 0) {
          st = (_STACK *)0x1;
        }
        else {
          st = (_STACK *)0x0;
        }
        goto LAB_0010fb54;
      }
      ERR_put_error(0xd,0xd5,0xcd,"asn_mime.c",0x241);
      ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar2 + 4));
    }
    sk_pop_free(st,mime_hdr_free + 1);
    st = (_STACK *)0x0;
  }
LAB_0010fb54:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)st;
}

