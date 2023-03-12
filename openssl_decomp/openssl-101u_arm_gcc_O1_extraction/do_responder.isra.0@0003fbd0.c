
void do_responder_isra_0(void **param_1,BIO **param_2,BIO *param_3)

{
  bool bVar1;
  long lVar2;
  BIO *bp;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  char local_420 [1028];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  lVar2 = BIO_ctrl(param_3,0x65,0,(void *)0x0);
  if (lVar2 < 1) {
    BIO_printf(bio_err,"Error accepting connection\n");
    ERR_print_errors(bio_err);
    uVar4 = 0;
  }
  else {
    bVar1 = false;
    bp = BIO_pop(param_3);
    *param_2 = bp;
    while (iVar3 = BIO_gets(bp,local_420,0x400), 0 < iVar3) {
      if ((!bVar1) && (iVar3 = strncmp(local_420,"POST",4), iVar3 != 0)) {
        BIO_printf(bio_err,"Invalid request\n");
        uVar4 = 1;
        goto LAB_0003fc3e;
      }
      if (local_420[0] == '\r' || local_420[0] == '\n') {
        pvVar5 = ASN1_d2i_bio(OCSP_REQUEST_new + 1,d2i_OCSP_REQUEST + 1,bp,(void **)0x0);
        if (pvVar5 == (void *)0x0) {
          BIO_printf(bio_err,"Error parsing OCSP request\n");
          ERR_print_errors(bio_err);
        }
        *param_1 = pvVar5;
        uVar4 = 1;
        goto LAB_0003fc3e;
      }
      bVar1 = true;
    }
    uVar4 = 1;
  }
LAB_0003fc3e:
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}

