
uchar * ssl3_ctrl(SSL *param_1,int param_2,uchar *param_3,RSA *param_4)

{
  uint uVar1;
  int iVar2;
  uchar *puVar3;
  RSA *pRVar4;
  cert_st *pcVar5;
  DH *pDVar6;
  size_t sVar7;
  char *pcVar8;
  SSL_METHOD *pSVar9;
  int line;
  
  if (((param_2 - 5U < 2) || (param_2 - 2U < 2)) &&
     (iVar2 = ssl_cert_inst(&param_1->cert), iVar2 == 0)) {
    line = 0xc50;
    iVar2 = 0x41;
    goto LAB_0809fe8d;
  }
  switch(param_2) {
  default:
    goto switchD_0809fe5c_caseD_0;
  case 1:
    pcVar5 = param_1->cert;
    if ((pcVar5 != (cert_st *)0x0) && (*(int *)(pcVar5 + 0x18) == 0)) {
      if (*(EVP_PKEY **)(pcVar5 + 0x34) == (EVP_PKEY *)0x0) {
        return (uchar *)0x1;
      }
      iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(pcVar5 + 0x34));
      return (uchar *)(uint)(0x40 < iVar2);
    }
    goto switchD_0809fe5c_caseD_0;
  case 2:
    if (param_4 == (RSA *)0x0) {
      line = 0xc75;
      iVar2 = 0x43;
    }
    else {
      pRVar4 = RSAPrivateKey_dup(param_4);
      if (pRVar4 != (RSA *)0x0) {
        pcVar5 = param_1->cert;
        if (*(RSA **)(pcVar5 + 0x18) != (RSA *)0x0) {
          RSA_free(*(RSA **)(pcVar5 + 0x18));
          pcVar5 = param_1->cert;
        }
        *(RSA **)(pcVar5 + 0x18) = pRVar4;
        return (uchar *)0x1;
      }
      line = 0xc79;
      iVar2 = 4;
    }
    goto LAB_0809fe8d;
  case 3:
    if (param_4 == (RSA *)0x0) {
      line = 0xc8e;
      iVar2 = 0x43;
    }
    else {
      pDVar6 = DHparams_dup((DH *)param_4);
      if (pDVar6 != (DH *)0x0) {
        pcVar5 = param_1->cert;
        if (*(DH **)(pcVar5 + 0x20) != (DH *)0x0) {
          DH_free(*(DH **)(pcVar5 + 0x20));
          pcVar5 = param_1->cert;
        }
        *(DH **)(pcVar5 + 0x20) = pDVar6;
        return (uchar *)0x1;
      }
      line = 0xc92;
      iVar2 = 5;
    }
    goto LAB_0809fe8d;
  case 4:
    if (param_4 == (RSA *)0x0) {
      line = 0xca8;
      iVar2 = 0x43;
    }
    else {
      iVar2 = EC_KEY_up_ref((EC_KEY *)param_4);
      if (iVar2 == 0) {
        line = 0xcac;
        iVar2 = 0x2b;
      }
      else {
        if (((*(byte *)((int)&param_1->references + 2) & 8) != 0) ||
           (iVar2 = EC_KEY_generate_key((EC_KEY *)param_4), iVar2 != 0)) {
          pcVar5 = param_1->cert;
          if (*(EC_KEY **)(pcVar5 + 0x28) != (EC_KEY *)0x0) {
            EC_KEY_free(*(EC_KEY **)(pcVar5 + 0x28));
            pcVar5 = param_1->cert;
          }
          *(RSA **)(pcVar5 + 0x28) = param_4;
          return (uchar *)0x1;
        }
        EC_KEY_free((EC_KEY *)param_4);
        line = 0xcb3;
        iVar2 = 0x2b;
      }
    }
    goto LAB_0809fe8d;
  case 5:
    line = 0xc84;
    goto LAB_0809ffa8;
  case 6:
    line = 0xc9d;
    goto LAB_0809ffa8;
  case 7:
    line = 0xcbf;
LAB_0809ffa8:
    iVar2 = 0x42;
    goto LAB_0809fe8d;
  case 8:
    puVar3 = (uchar *)param_1->hit;
    break;
  case 10:
    puVar3 = (uchar *)param_1->s3->num_renegotiations;
    break;
  case 0xb:
    puVar3 = (uchar *)param_1->s3->num_renegotiations;
    param_1->s3->num_renegotiations = 0;
    break;
  case 0xc:
    puVar3 = (uchar *)param_1->s3->total_renegotiations;
    break;
  case 0xd:
    puVar3 = (uchar *)param_1->s3->flags;
    break;
  case 0x37:
    if (param_3 == (uchar *)0x0) {
      if (param_1->tlsext_debug_arg != (void *)0x0) {
        CRYPTO_free(param_1->tlsext_debug_arg);
      }
      param_1->tlsext_debug_arg = (void *)0x0;
      if (param_4 == (RSA *)0x0) {
        return (uchar *)0x1;
      }
      sVar7 = strlen((char *)param_4);
      if (sVar7 - 1 < 0xff) {
        pcVar8 = BUF_strdup((char *)param_4);
        param_1->tlsext_debug_arg = pcVar8;
        if (pcVar8 != (char *)0x0) {
          return (uchar *)0x1;
        }
        line = 0xcd6;
        iVar2 = 0x44;
      }
      else {
        line = 0xcd2;
        iVar2 = 0x13f;
      }
    }
    else {
      line = 0xcda;
      iVar2 = 0x140;
    }
LAB_0809fe8d:
    ERR_put_error(0x14,0xd5,iVar2,"s3_lib.c",line);
    puVar3 = (uchar *)0x0;
    break;
  case 0x39:
    param_1->tlsext_debug_cb = (_func_3155 *)param_4;
    puVar3 = (uchar *)0x1;
    break;
  case 0x41:
    param_1->servername_done = (int)param_3;
    puVar3 = (uchar *)0x1;
    break;
  case 0x42:
    *(stack_st_OCSP_RESPID **)param_4 = param_1->tlsext_ocsp_ids;
    puVar3 = (uchar *)0x1;
    break;
  case 0x43:
    param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)param_4;
    puVar3 = (uchar *)0x1;
    break;
  case 0x44:
    *(int *)param_4 = param_1->tlsext_status_expected;
    puVar3 = (uchar *)0x1;
    break;
  case 0x45:
    param_1->tlsext_status_expected = (int)param_4;
    puVar3 = (uchar *)0x1;
    break;
  case 0x46:
    *(X509_EXTENSIONS **)param_4 = param_1->tlsext_ocsp_exts;
    puVar3 = param_1->tlsext_ocsp_resp;
    break;
  case 0x47:
    if (param_1->tlsext_ocsp_exts != (X509_EXTENSIONS *)0x0) {
      CRYPTO_free(param_1->tlsext_ocsp_exts);
    }
    param_1->tlsext_ocsp_exts = (X509_EXTENSIONS *)param_4;
    param_1->tlsext_ocsp_resp = param_3;
    puVar3 = (uchar *)0x1;
    break;
  case 0x55:
    iVar2 = SSL_version(param_1);
    if ((iVar2 != 0xfeff) && (iVar2 = SSL_version(param_1), iVar2 != 0x100)) {
      puVar3 = (uchar *)tls1_heartbeat();
      return puVar3;
    }
    puVar3 = (uchar *)dtls1_heartbeat();
    return puVar3;
  case 0x56:
    puVar3 = (uchar *)param_1->tlsext_heartbeat;
    break;
  case 0x57:
    if (param_3 == (uchar *)0x0) {
      param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffb);
      puVar3 = (uchar *)0x1;
    }
    else {
      param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 4);
      puVar3 = (uchar *)0x1;
    }
    break;
  case 0x77:
    iVar2 = **(int **)param_1->psk_server_callback;
    if (param_1->version == iVar2) {
      return (uchar *)0x1;
    }
    pSVar9 = SSLv23_method();
    if (iVar2 == pSVar9->version) {
      uVar1 = param_1->references;
      if ((uVar1 & 0x8000000) == 0) {
        return (uchar *)(uint)(param_1->version == 0x303);
      }
      if ((uVar1 & 0x10000000) == 0) {
        return (uchar *)(uint)(param_1->version == 0x302);
      }
      if ((uVar1 & 0x4000000) == 0) {
        return (uchar *)(uint)(param_1->version == 0x301);
      }
      if ((uVar1 & 0x2000000) == 0) {
        return (uchar *)(uint)(param_1->version == 0x300);
      }
      if ((uVar1 & 0x1000000) == 0) {
        return (uchar *)(uint)(param_1->version == 2);
      }
    }
switchD_0809fe5c_caseD_0:
    puVar3 = (uchar *)0x0;
  }
  return puVar3;
}

