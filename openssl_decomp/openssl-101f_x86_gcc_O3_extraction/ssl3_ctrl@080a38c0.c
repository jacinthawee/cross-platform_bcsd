
uchar * ssl3_ctrl(SSL *param_1,int param_2,uchar *param_3,RSA *param_4)

{
  int iVar1;
  uchar *puVar2;
  RSA *pRVar3;
  DH *dh;
  cert_st *pcVar4;
  size_t sVar5;
  char *pcVar6;
  int line;
  
  if (((param_2 - 5U < 2) || (param_2 - 2U < 2)) &&
     (iVar1 = ssl_cert_inst(&param_1->cert), iVar1 == 0)) {
    line = 0xc25;
    iVar1 = 0x41;
    goto LAB_080a391d;
  }
  switch(param_2) {
  default:
    goto switchD_080a38ec_caseD_0;
  case 1:
    pcVar4 = param_1->cert;
    if (pcVar4 == (cert_st *)0x0) {
      return (uchar *)0x0;
    }
    if (*(int *)(pcVar4 + 0x18) != 0) {
      return (uchar *)0x0;
    }
    if (*(EVP_PKEY **)(pcVar4 + 0x34) != (EVP_PKEY *)0x0) {
      iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(pcVar4 + 0x34));
      return (uchar *)(uint)(0x40 < iVar1);
    }
    goto LAB_080a3ab0;
  case 2:
    if (param_4 == (RSA *)0x0) {
      line = 0xc4b;
      iVar1 = 0x43;
    }
    else {
      pRVar3 = RSAPrivateKey_dup(param_4);
      if (pRVar3 != (RSA *)0x0) {
        pcVar4 = param_1->cert;
        if (*(RSA **)(pcVar4 + 0x18) != (RSA *)0x0) {
          RSA_free(*(RSA **)(pcVar4 + 0x18));
          pcVar4 = param_1->cert;
        }
        *(RSA **)(pcVar4 + 0x18) = pRVar3;
        goto LAB_080a3ab0;
      }
      line = 0xc50;
      iVar1 = 4;
    }
    goto LAB_080a391d;
  case 3:
    if (param_4 == (RSA *)0x0) {
      line = 0xc66;
      iVar1 = 0x43;
    }
    else {
      dh = DHparams_dup((DH *)param_4);
      if (dh == (DH *)0x0) {
        line = 0xc6b;
        iVar1 = 5;
      }
      else {
        if (((*(byte *)((int)&param_1->references + 2) & 0x10) != 0) ||
           (iVar1 = DH_generate_key(dh), iVar1 != 0)) {
          pcVar4 = param_1->cert;
          if (*(DH **)(pcVar4 + 0x20) != (DH *)0x0) {
            DH_free(*(DH **)(pcVar4 + 0x20));
            pcVar4 = param_1->cert;
          }
          *(DH **)(pcVar4 + 0x20) = dh;
          return (uchar *)0x1;
        }
        DH_free(dh);
        line = 0xc73;
        iVar1 = 5;
      }
    }
    goto LAB_080a391d;
  case 4:
    if (param_4 == (RSA *)0x0) {
      line = 0xc8b;
      iVar1 = 0x43;
    }
    else {
      iVar1 = EC_KEY_up_ref((EC_KEY *)param_4);
      if (iVar1 == 0) {
        line = 0xc90;
        iVar1 = 0x2b;
      }
      else {
        if (((*(byte *)((int)&param_1->references + 2) & 8) != 0) ||
           (iVar1 = EC_KEY_generate_key((EC_KEY *)param_4), iVar1 != 0)) {
          pcVar4 = param_1->cert;
          if (*(EC_KEY **)(pcVar4 + 0x28) != (EC_KEY *)0x0) {
            EC_KEY_free(*(EC_KEY **)(pcVar4 + 0x28));
            pcVar4 = param_1->cert;
          }
          *(RSA **)(pcVar4 + 0x28) = param_4;
          return (uchar *)0x1;
        }
        EC_KEY_free((EC_KEY *)param_4);
        line = 0xc99;
        iVar1 = 0x2b;
      }
    }
    goto LAB_080a391d;
  case 5:
    line = 0xc5b;
    goto LAB_080a3948;
  case 6:
    line = 0xc7f;
    goto LAB_080a3948;
  case 7:
    line = 0xca5;
LAB_080a3948:
    iVar1 = 0x42;
    goto LAB_080a391d;
  case 8:
    puVar2 = (uchar *)param_1->hit;
    break;
  case 10:
    puVar2 = (uchar *)param_1->s3->num_renegotiations;
    break;
  case 0xb:
    puVar2 = (uchar *)param_1->s3->num_renegotiations;
    param_1->s3->num_renegotiations = 0;
    break;
  case 0xc:
    puVar2 = (uchar *)param_1->s3->total_renegotiations;
    break;
  case 0xd:
    puVar2 = (uchar *)param_1->s3->flags;
    break;
  case 0x37:
    if (param_3 == (uchar *)0x0) {
      if (param_1->tlsext_debug_arg != (void *)0x0) {
        CRYPTO_free(param_1->tlsext_debug_arg);
      }
      param_1->tlsext_debug_arg = (void *)0x0;
      if (param_4 == (RSA *)0x0) goto LAB_080a3ab0;
      sVar5 = strlen((char *)param_4);
      if (sVar5 < 0x100) {
        pcVar6 = BUF_strdup((char *)param_4);
        param_1->tlsext_debug_arg = pcVar6;
        if (pcVar6 != (char *)0x0) goto LAB_080a3ab0;
        line = 0xcbc;
        iVar1 = 0x44;
      }
      else {
        line = 0xcb7;
        iVar1 = 0x13f;
      }
    }
    else {
      line = 0xcc2;
      iVar1 = 0x140;
    }
LAB_080a391d:
    ERR_put_error(0x14,0xd5,iVar1,"s3_lib.c",line);
switchD_080a38ec_caseD_0:
    puVar2 = (uchar *)0x0;
    break;
  case 0x39:
    param_1->tlsext_debug_cb = (_func_3155 *)param_4;
    puVar2 = (uchar *)0x1;
    break;
  case 0x41:
    param_1->servername_done = (int)param_3;
    puVar2 = (uchar *)0x1;
    break;
  case 0x42:
    *(stack_st_OCSP_RESPID **)param_4 = param_1->tlsext_ocsp_ids;
    puVar2 = (uchar *)0x1;
    break;
  case 0x43:
    param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)param_4;
    puVar2 = (uchar *)0x1;
    break;
  case 0x44:
    *(int *)param_4 = param_1->tlsext_status_expected;
    puVar2 = (uchar *)0x1;
    break;
  case 0x45:
    param_1->tlsext_status_expected = (int)param_4;
    puVar2 = (uchar *)0x1;
    break;
  case 0x46:
    *(X509_EXTENSIONS **)param_4 = param_1->tlsext_ocsp_exts;
    puVar2 = param_1->tlsext_ocsp_resp;
    break;
  case 0x47:
    if (param_1->tlsext_ocsp_exts != (X509_EXTENSIONS *)0x0) {
      CRYPTO_free(param_1->tlsext_ocsp_exts);
    }
    param_1->tlsext_ocsp_exts = (X509_EXTENSIONS *)param_4;
    param_1->tlsext_ocsp_resp = param_3;
    puVar2 = (uchar *)0x1;
    break;
  case 0x55:
    iVar1 = SSL_version(param_1);
    if ((iVar1 != 0xfeff) && (iVar1 = SSL_version(param_1), iVar1 != 0x100)) {
      puVar2 = (uchar *)tls1_heartbeat();
      return puVar2;
    }
    puVar2 = (uchar *)dtls1_heartbeat();
    return puVar2;
  case 0x56:
    puVar2 = (uchar *)param_1->tlsext_heartbeat;
    break;
  case 0x57:
    if (param_3 != (uchar *)0x0) {
      param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 4);
      return (uchar *)0x1;
    }
    param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffb);
LAB_080a3ab0:
    puVar2 = (uchar *)0x1;
  }
  return puVar2;
}

