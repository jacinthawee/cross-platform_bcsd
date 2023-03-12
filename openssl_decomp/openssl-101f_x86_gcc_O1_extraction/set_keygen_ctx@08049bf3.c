
EVP_PKEY * __regparm3
set_keygen_ctx(BIO *param_1_00,char *param_2_00,int *param_3_00,long *param_1,char **param_2,
              ENGINE *param_3)

{
  char cVar1;
  long p1;
  BIO *bp;
  X509 *x;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  EVP_PKEY *ctx;
  int iVar4;
  uint uVar5;
  EVP_PKEY *pkey;
  char *pcVar6;
  int in_GS_OFFSET;
  byte bVar7;
  char *pcVar8;
  ENGINE *local_28;
  ENGINE *local_24;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2_00 == (char *)0x0) {
    *param_3_00 = 6;
    p1 = *param_1;
    goto LAB_08049efe;
  }
  if ((byte)(*param_2_00 - 0x30U) < 10) {
    *param_3_00 = 6;
LAB_08049d17:
    p1 = strtol(param_2_00,(char **)0x0,10);
    *param_1 = p1;
LAB_08049efe:
    pkey = (EVP_PKEY *)0x0;
    if (param_2 != (char **)0x0) {
LAB_08049e50:
      pEVar3 = EVP_PKEY_asn1_find(&local_28,*param_3_00);
      if (pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        BIO_puts(param_1_00,"Internal error: can\'t find key algorithm\n");
        ctx = (EVP_PKEY *)0x0;
        goto LAB_08049e7b;
      }
      EVP_PKEY_asn1_get0_info
                ((int *)0x0,(int *)0x0,(int *)0x0,(char **)0x0,(char **)&local_24,pEVar3);
      pcVar8 = BUF_strdup((char *)local_24);
      *param_2 = pcVar8;
      if (local_28 != (ENGINE *)0x0) {
        ENGINE_finish(local_28);
      }
      if (pkey != (EVP_PKEY *)0x0) goto LAB_08049ed5;
    }
    ctx = (EVP_PKEY *)EVP_PKEY_CTX_new_id(*param_3_00,param_3);
  }
  else {
    iVar4 = strncmp(param_2_00,"param:",6);
    if (iVar4 != 0) {
      pcVar8 = strchr(param_2_00,0x3a);
      if (pcVar8 == (char *)0x0) {
        uVar5 = 0xffffffff;
        pcVar6 = param_2_00;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + (uint)bVar7 * -2 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar5 - 1;
      }
      else {
        iVar4 = (int)pcVar8 - (int)param_2_00;
      }
      pEVar3 = EVP_PKEY_asn1_find_str(&local_24,param_2_00,iVar4);
      if (pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        ctx = (EVP_PKEY *)0x0;
        BIO_printf(param_1_00,"Unknown algorithm %.*s\n",iVar4,param_2_00);
        goto LAB_08049e7b;
      }
      EVP_PKEY_asn1_get0_info((int *)0x0,param_3_00,(int *)0x0,(char **)0x0,(char **)0x0,pEVar3);
      if (local_24 != (ENGINE *)0x0) {
        ENGINE_finish(local_24);
      }
      if (*param_3_00 == 6) {
        p1 = -1;
        if (pcVar8 != (char *)0x0) {
          param_2_00 = pcVar8 + 1;
          goto LAB_08049d17;
        }
      }
      else {
        if (pcVar8 != (char *)0x0) {
          param_2_00 = pcVar8 + 1;
          goto LAB_08049d44;
        }
        p1 = -1;
      }
      goto LAB_08049efe;
    }
    param_2_00 = param_2_00 + 6;
LAB_08049d44:
    p1 = -1;
    if (param_2_00 == (char *)0x0) goto LAB_08049efe;
    bp = BIO_new_file(param_2_00,"r");
    if (bp == (BIO *)0x0) {
      BIO_printf(param_1_00,"Can\'t open parameter file %s\n",param_2_00,0);
      ctx = (EVP_PKEY *)0x0;
      goto LAB_08049e7b;
    }
    pkey = PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
    if (pkey == (EVP_PKEY *)0x0) {
      BIO_ctrl(bp,1,0,(void *)0x0);
      x = PEM_read_bio_X509(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
      if (x != (X509 *)0x0) {
        pkey = X509_get_pubkey(x);
        X509_free(x);
      }
    }
    iVar4 = BIO_free(bp);
    if (pkey == (EVP_PKEY *)0x0) {
      BIO_printf(param_1_00,"Error reading parameter file %s\n",param_2_00,iVar4);
      ctx = pkey;
      goto LAB_08049e7b;
    }
    iVar4 = *param_3_00;
    if (iVar4 == -1) {
      iVar4 = EVP_PKEY_id(pkey);
      *param_3_00 = iVar4;
    }
    else {
      iVar2 = EVP_PKEY_base_id(pkey);
      if (iVar4 != iVar2) {
        BIO_printf(param_1_00,"Key Type does not match parameters\n",iVar2,iVar2);
        ctx = (EVP_PKEY *)0x0;
        EVP_PKEY_free(pkey);
        goto LAB_08049e7b;
      }
    }
    if (param_2 != (char **)0x0) goto LAB_08049e50;
LAB_08049ed5:
    ctx = (EVP_PKEY *)EVP_PKEY_CTX_new(pkey,param_3);
    iVar4 = EVP_PKEY_bits(pkey);
    *param_1 = iVar4;
    EVP_PKEY_free(pkey);
  }
  if (ctx == (EVP_PKEY *)0x0) {
    pcVar8 = "Error allocating keygen context\n";
  }
  else {
    iVar4 = EVP_PKEY_keygen_init((EVP_PKEY_CTX *)ctx);
    if (0 < iVar4) {
      if (((*param_3_00 == 6) && (p1 != -1)) &&
         (iVar4 = EVP_PKEY_CTX_ctrl((EVP_PKEY_CTX *)ctx,6,4,0x1003,p1,(void *)0x0), iVar4 < 1)) {
        BIO_puts(param_1_00,"Error setting RSA keysize\n");
        ERR_print_errors(param_1_00);
        EVP_PKEY_CTX_free((EVP_PKEY_CTX *)ctx);
        ctx = (EVP_PKEY *)0x0;
      }
      goto LAB_08049e7b;
    }
    pcVar8 = "Error initializing keygen context\n";
  }
  BIO_puts(param_1_00,pcVar8);
  ERR_print_errors(param_1_00);
  ctx = (EVP_PKEY *)0x0;
LAB_08049e7b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ctx;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

