
RSA * ssl3_ctx_ctrl(int param_1,int param_2,int param_3,RSA *param_4)

{
  size_t sVar1;
  _STACK *st;
  RSA *pRVar2;
  char *pcVar3;
  RSA *pRVar4;
  ENGINE *pEVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  int iVar8;
  RSA_METHOD *pRVar9;
  BIGNUM *pBVar10;
  
  iVar8 = *(int *)(param_1 + 0xb0);
  switch(param_2) {
  case 1:
    if (*(int *)(iVar8 + 0x18) == 0) {
      if (*(EVP_PKEY **)(iVar8 + 0x34) != (EVP_PKEY *)0x0) {
        iVar8 = EVP_PKEY_size(*(EVP_PKEY **)(iVar8 + 0x34));
        return (RSA *)(uint)(0x40 < iVar8);
      }
      goto LAB_0004c1c2;
    }
  default:
switchD_0004bf76_caseD_8:
    pRVar2 = (RSA *)0x0;
    break;
  case 2:
    if ((param_4 != (RSA *)0x0) && (pRVar2 = RSAPrivateKey_dup(param_4), pRVar2 != (RSA *)0x0)) {
      if (*(RSA **)(iVar8 + 0x18) != (RSA *)0x0) {
        RSA_free(*(RSA **)(iVar8 + 0x18));
      }
      *(RSA **)(iVar8 + 0x18) = pRVar2;
      goto LAB_0004c1c2;
    }
    ERR_put_error(0x14,0x85,4,"s3_lib.c",0xdb1);
    goto switchD_0004bf76_caseD_8;
  case 3:
    pRVar2 = (RSA *)DHparams_dup((DH *)param_4);
    if (pRVar2 == (RSA *)0x0) {
      ERR_put_error(0x14,0x85,5,"s3_lib.c",0xdc9);
    }
    else {
      if (*(DH **)(iVar8 + 0x20) != (DH *)0x0) {
        DH_free(*(DH **)(iVar8 + 0x20));
      }
      *(RSA **)(iVar8 + 0x20) = pRVar2;
      pRVar2 = (RSA *)0x1;
    }
    break;
  case 4:
    if (param_4 == (RSA *)0x0) {
      ERR_put_error(0x14,0x85,0x2b,"s3_lib.c",0xde1);
      pRVar2 = param_4;
    }
    else {
      pRVar2 = (RSA *)EC_KEY_dup((EC_KEY *)param_4);
      if (pRVar2 == (RSA *)0x0) {
        ERR_put_error(0x14,0x85,0x10,"s3_lib.c",0xde6);
      }
      else if ((*(int *)(param_1 + 0xa4) << 0xc < 0) ||
              (pRVar4 = (RSA *)EC_KEY_generate_key((EC_KEY *)pRVar2), pRVar4 != (RSA *)0x0)) {
        if (*(EC_KEY **)(iVar8 + 0x28) != (EC_KEY *)0x0) {
          EC_KEY_free(*(EC_KEY **)(iVar8 + 0x28));
        }
        *(RSA **)(iVar8 + 0x28) = pRVar2;
        pRVar2 = (RSA *)0x1;
      }
      else {
        EC_KEY_free((EC_KEY *)pRVar2);
        ERR_put_error(0x14,0x85,0x2b,"s3_lib.c",0xdec);
        pRVar2 = pRVar4;
      }
    }
    break;
  case 5:
    iVar8 = 0xdbd;
    goto LAB_0004c154;
  case 6:
    iVar8 = 0xdd6;
    goto LAB_0004c154;
  case 7:
    iVar8 = 0xdfa;
LAB_0004c154:
    ERR_put_error(0x14,0x85,0x42,"s3_lib.c",iVar8);
    return (RSA *)0x0;
  case 0xe:
    st = *(_STACK **)(param_1 + 0x94);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(param_1 + 0x94) = st;
      if (st == (_STACK *)0x0) goto switchD_0004bf76_caseD_8;
    }
    sk_push(st,param_4);
    pRVar2 = (RSA *)0x1;
    break;
  case 0x36:
    *(RSA **)(param_1 + 0x104) = param_4;
    pRVar2 = (RSA *)0x1;
    break;
  case 0x3a:
  case 0x3b:
    pRVar2 = (RSA *)0x30;
    if (param_4 != (RSA *)0x0) {
      if (param_3 == 0x30) {
        if (param_2 == 0x3b) {
          pRVar9 = param_4->meth;
          pEVar5 = param_4->engine;
          iVar8 = param_4->pad;
          *(long *)(param_1 + 0x10c) = param_4->version;
          *(RSA_METHOD **)(param_1 + 0x110) = pRVar9;
          *(int *)(param_1 + 0x108) = iVar8;
          *(ENGINE **)(param_1 + 0x114) = pEVar5;
          pBVar10 = param_4->e;
          pBVar7 = param_4->d;
          pBVar6 = param_4->p;
          *(BIGNUM **)(param_1 + 0x118) = param_4->n;
          *(BIGNUM **)(param_1 + 0x11c) = pBVar10;
          *(BIGNUM **)(param_1 + 0x120) = pBVar7;
          *(BIGNUM **)(param_1 + 0x124) = pBVar6;
          pBVar10 = param_4->dmp1;
          pBVar6 = param_4->dmq1;
          pBVar7 = param_4->iqmp;
          *(BIGNUM **)(param_1 + 0x128) = param_4->q;
          *(BIGNUM **)(param_1 + 300) = pBVar10;
          *(BIGNUM **)(param_1 + 0x130) = pBVar6;
          *(BIGNUM **)(param_1 + 0x134) = pBVar7;
          pRVar2 = (RSA *)0x1;
        }
        else {
          pRVar9 = *(RSA_METHOD **)(param_1 + 0x110);
          pEVar5 = *(ENGINE **)(param_1 + 0x114);
          iVar8 = *(int *)(param_1 + 0x108);
          param_4->version = *(long *)(param_1 + 0x10c);
          param_4->meth = pRVar9;
          param_4->pad = iVar8;
          param_4->engine = pEVar5;
          pBVar6 = *(BIGNUM **)(param_1 + 0x120);
          pBVar7 = *(BIGNUM **)(param_1 + 0x124);
          pBVar10 = *(BIGNUM **)(param_1 + 0x118);
          param_4->e = *(BIGNUM **)(param_1 + 0x11c);
          param_4->d = pBVar6;
          param_4->n = pBVar10;
          param_4->p = pBVar7;
          pBVar10 = *(BIGNUM **)(param_1 + 300);
          pBVar6 = *(BIGNUM **)(param_1 + 0x130);
          pBVar7 = *(BIGNUM **)(param_1 + 0x134);
          param_4->q = *(BIGNUM **)(param_1 + 0x128);
          param_4->dmp1 = pBVar10;
          param_4->dmq1 = pBVar6;
          param_4->iqmp = pBVar7;
          pRVar2 = (RSA *)0x1;
        }
      }
      else {
        ERR_put_error(0x14,0x85,0x145,"s3_lib.c",0xe0a);
        pRVar2 = (RSA *)0x0;
      }
    }
    break;
  case 0x40:
    *(RSA **)(param_1 + 0x140) = param_4;
    pRVar2 = (RSA *)0x1;
    break;
  case 0x4e:
    *(RSA **)(param_1 + 0x164) = param_4;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    pRVar2 = (RSA *)0x1;
    break;
  case 0x4f:
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    if (*(void **)(param_1 + 0x174) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x174));
    }
    *(undefined4 *)(param_1 + 0x174) = 0;
    if (param_4 != (RSA *)0x0) {
      sVar1 = strlen((char *)param_4);
      if ((0xff < sVar1) || (*(char *)&param_4->pad == '\0')) {
        ERR_put_error(0x14,0x85,0x165,"s3_lib.c",0xe2e);
        return (RSA *)0x0;
      }
      pcVar3 = BUF_strdup((char *)param_4);
      *(char **)(param_1 + 0x174) = pcVar3;
      if (pcVar3 == (char *)0x0) {
        ERR_put_error(0x14,0x85,0x44,"s3_lib.c",0xe32);
        return (RSA *)0x0;
      }
    }
    goto LAB_0004c1c2;
  case 0x50:
    *(int *)(param_1 + 0x19c) = param_3;
    pRVar2 = (RSA *)0x1;
    break;
  case 0x51:
    *(RSA **)(param_1 + 0x198) = param_4;
    *(undefined4 *)(param_1 + 0x170) = 0x4b7c9;
    pRVar2 = (RSA *)0x1;
    break;
  case 0x52:
    param_4->pad = *(int *)(param_1 + 0x94);
    pRVar2 = (RSA *)0x1;
    break;
  case 0x53:
    if (*(_STACK **)(param_1 + 0x94) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x94),X509_free + 1);
      *(undefined4 *)(param_1 + 0x94) = 0;
      return (RSA *)0x1;
    }
LAB_0004c1c2:
    pRVar2 = (RSA *)0x1;
  }
  return pRVar2;
}

