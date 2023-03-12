
RSA * ssl3_ctrl(SSL *param_1,int param_2,uchar *param_3,RSA *param_4)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  RSA *pRVar4;
  DH *pDVar5;
  SSL_METHOD *pSVar6;
  uint uVar7;
  cert_st *pcVar8;
  bool bVar9;
  bool bVar10;
  
  bVar10 = param_2 != 5;
  bVar9 = param_2 - 5U == 1;
  if (1 < param_2 - 5U) {
    bVar10 = param_2 != 2;
    bVar9 = param_2 == 3;
  }
  if ((!bVar10 || bVar9) && (iVar1 = ssl_cert_inst(&param_1->cert), iVar1 == 0)) {
    ERR_put_error(0x14,0xd5,0x41,"s3_lib.c",0xc50);
    return (RSA *)0x0;
  }
  switch(param_2) {
  case 1:
    pcVar8 = param_1->cert;
    if ((pcVar8 == (cert_st *)0x0) || (*(int *)(pcVar8 + 0x18) != 0)) goto switchD_0004ba4e_caseD_9;
    if (*(EVP_PKEY **)(pcVar8 + 0x34) != (EVP_PKEY *)0x0) {
      iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(pcVar8 + 0x34));
      return (RSA *)(uint)(0x40 < iVar1);
    }
    goto LAB_0004bbfe;
  case 2:
    iVar1 = 0xc75;
    if (param_4 == (RSA *)0x0) goto LAB_0004bdc0;
    pRVar4 = RSAPrivateKey_dup(param_4);
    if (pRVar4 == (RSA *)0x0) {
      ERR_put_error(0x14,0xd5,4,"s3_lib.c",0xc79);
      return (RSA *)0x0;
    }
    pcVar8 = param_1->cert;
    if (*(RSA **)(pcVar8 + 0x18) != (RSA *)0x0) {
      RSA_free(*(RSA **)(pcVar8 + 0x18));
      pcVar8 = param_1->cert;
    }
    *(RSA **)(pcVar8 + 0x18) = pRVar4;
    goto LAB_0004bbfe;
  case 3:
    if (param_4 != (RSA *)0x0) {
      pDVar5 = DHparams_dup((DH *)param_4);
      if (pDVar5 != (DH *)0x0) {
        pcVar8 = param_1->cert;
        if (*(DH **)(pcVar8 + 0x20) != (DH *)0x0) {
          DH_free(*(DH **)(pcVar8 + 0x20));
          pcVar8 = param_1->cert;
        }
        *(DH **)(pcVar8 + 0x20) = pDVar5;
        return (RSA *)0x1;
      }
      ERR_put_error(0x14,0xd5,5,"s3_lib.c",0xc92);
      return (RSA *)0x0;
    }
    iVar1 = 0xc8e;
    goto LAB_0004bdc0;
  case 4:
    iVar1 = 0xca8;
    if (param_4 != (RSA *)0x0) {
      iVar1 = EC_KEY_up_ref((EC_KEY *)param_4);
      if (iVar1 == 0) {
        ERR_put_error(0x14,0xd5,0x2b,"s3_lib.c",0xcac);
        return (RSA *)0x0;
      }
      if ((-1 < param_1->references << 0xc) &&
         (iVar1 = EC_KEY_generate_key((EC_KEY *)param_4), iVar1 == 0)) {
        EC_KEY_free((EC_KEY *)param_4);
        ERR_put_error(0x14,0xd5,0x2b,"s3_lib.c",0xcb3);
        return (RSA *)0x0;
      }
      pcVar8 = param_1->cert;
      if (*(EC_KEY **)(pcVar8 + 0x28) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)(pcVar8 + 0x28));
        pcVar8 = param_1->cert;
      }
      *(RSA **)(pcVar8 + 0x28) = param_4;
      return (RSA *)0x1;
    }
LAB_0004bdc0:
    ERR_put_error(0x14,0xd5,0x43,"s3_lib.c",iVar1);
    break;
  case 5:
    iVar1 = 0xc84;
    goto LAB_0004bca4;
  case 6:
    iVar1 = 0xc9d;
    goto LAB_0004bca4;
  case 7:
    iVar1 = 0xcbf;
LAB_0004bca4:
    ERR_put_error(0x14,0xd5,0x42,"s3_lib.c",iVar1);
    return (RSA *)0x0;
  case 8:
    param_4 = (RSA *)param_1->hit;
    break;
  default:
switchD_0004ba4e_caseD_9:
    param_4 = (RSA *)0x0;
    break;
  case 10:
    param_4 = (RSA *)param_1->s3->num_renegotiations;
    break;
  case 0xb:
    param_4 = (RSA *)param_1->s3->num_renegotiations;
    param_1->s3->num_renegotiations = 0;
    break;
  case 0xc:
    param_4 = (RSA *)param_1->s3->total_renegotiations;
    break;
  case 0xd:
    param_4 = (RSA *)param_1->s3->flags;
    break;
  case 0x37:
    if (param_3 != (uchar *)0x0) {
      ERR_put_error(0x14,0xd5,0x140,"s3_lib.c",0xcda);
      return (RSA *)0x0;
    }
    if (param_1->tlsext_debug_arg != (void *)0x0) {
      CRYPTO_free(param_1->tlsext_debug_arg);
    }
    param_1->tlsext_debug_arg = (void *)0x0;
    if (param_4 != (RSA *)0x0) {
      sVar2 = strlen((char *)param_4);
      if (0xfe < sVar2 - 1) {
        ERR_put_error(0x14,0xd5,0x13f,"s3_lib.c",0xcd2);
        return (RSA *)0x0;
      }
      pcVar3 = BUF_strdup((char *)param_4);
      param_1->tlsext_debug_arg = pcVar3;
      if (pcVar3 == (char *)0x0) {
        ERR_put_error(0x14,0xd5,0x44,"s3_lib.c",0xcd6);
        return (RSA *)0x0;
      }
    }
    goto LAB_0004bbfe;
  case 0x39:
    param_1->tlsext_debug_cb = (_func_3155 *)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x41:
    param_1->servername_done = (int)param_3;
    param_4 = (RSA *)0x1;
    break;
  case 0x42:
    *(stack_st_OCSP_RESPID **)param_4 = param_1->tlsext_ocsp_ids;
    param_4 = (RSA *)0x1;
    break;
  case 0x43:
    param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x44:
    *(int *)param_4 = param_1->tlsext_status_expected;
    param_4 = (RSA *)0x1;
    break;
  case 0x45:
    param_1->tlsext_status_expected = (int)param_4;
    param_4 = (RSA *)0x1;
    break;
  case 0x46:
    pRVar4 = (RSA *)param_1->tlsext_ocsp_resp;
    *(X509_EXTENSIONS **)param_4 = param_1->tlsext_ocsp_exts;
    param_4 = pRVar4;
    break;
  case 0x47:
    if (param_1->tlsext_ocsp_exts != (X509_EXTENSIONS *)0x0) {
      CRYPTO_free(param_1->tlsext_ocsp_exts);
    }
    param_1->tlsext_ocsp_exts = (X509_EXTENSIONS *)param_4;
    param_1->tlsext_ocsp_resp = param_3;
    param_4 = (RSA *)0x1;
    break;
  case 0x55:
    iVar1 = SSL_version(param_1);
    if ((iVar1 != 0xfeff) && (iVar1 = SSL_version(param_1), iVar1 != 0x100)) {
      pRVar4 = (RSA *)tls1_heartbeat(param_1);
      return pRVar4;
    }
    pRVar4 = (RSA *)dtls1_heartbeat(param_1);
    return pRVar4;
  case 0x56:
    param_4 = (RSA *)param_1->tlsext_heartbeat;
    break;
  case 0x57:
    param_4 = (RSA *)0x1;
    if (param_3 == (uchar *)0x0) {
      param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffb);
    }
    else {
      param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 4);
    }
    break;
  case 0x77:
    iVar1 = **(int **)param_1->psk_server_callback;
    if (param_1->version != iVar1) {
      pSVar6 = SSLv23_method();
      if (iVar1 == pSVar6->version) {
        iVar1 = param_1->references;
        if (-1 < iVar1 << 4) {
          uVar7 = count_leading_zeroes(param_1->version + -0x303);
          return (RSA *)(uVar7 >> 5);
        }
        if (-1 < iVar1 << 3) {
          uVar7 = count_leading_zeroes(param_1->version + -0x302);
          return (RSA *)(uVar7 >> 5);
        }
        if (-1 < iVar1 << 5) {
          uVar7 = count_leading_zeroes(param_1->version + -0x301);
          return (RSA *)(uVar7 >> 5);
        }
        if (-1 < iVar1 << 6) {
          return (RSA *)(uint)(param_1->version == 0x300);
        }
        if (-1 < iVar1 << 7) {
          return (RSA *)(uint)(param_1->version == 2);
        }
      }
      goto switchD_0004ba4e_caseD_9;
    }
LAB_0004bbfe:
    param_4 = (RSA *)0x1;
  }
  return param_4;
}

