
undefined4 __regparm3 do_responder_isra_0(void **param_1,BIO **param_2,BIO *param_3)

{
  long lVar1;
  BIO *bp;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  char *pcVar6;
  int in_GS_OFFSET;
  bool bVar7;
  byte bVar8;
  char local_420 [1024];
  int local_20;
  
  bVar8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar1 = BIO_ctrl(param_3,0x65,0,(void *)0x0);
  if (lVar1 < 1) {
    BIO_printf(bio_err,"Error accepting connection\n");
    ERR_print_errors(bio_err);
    uVar3 = 0;
  }
  else {
    bp = BIO_pop(param_3);
    *param_2 = bp;
    bVar7 = false;
    do {
      iVar2 = BIO_gets(bp,local_420,0x400);
      if (iVar2 < 1) {
        uVar3 = 1;
        goto LAB_0808e1b5;
      }
      bVar7 = !bVar7;
      if (bVar7) {
        iVar2 = 4;
        pcVar5 = local_420;
        pcVar6 = "POST";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar7 = *pcVar5 == *pcVar6;
          pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
          pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
        } while (bVar7);
        if (!bVar7) {
          BIO_printf(bio_err,"Invalid request\n");
          uVar3 = 1;
          goto LAB_0808e1b5;
        }
      }
      bVar7 = true;
    } while ((local_420[0] != '\r') && (local_420[0] != '\n'));
    pvVar4 = ASN1_d2i_bio(OCSP_REQUEST_new,d2i_OCSP_REQUEST,bp,(void **)0x0);
    if (pvVar4 == (void *)0x0) {
      BIO_printf(bio_err,"Error parsing OCSP request\n");
      ERR_print_errors(bio_err);
    }
    *param_1 = pvVar4;
    uVar3 = 1;
  }
LAB_0808e1b5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

