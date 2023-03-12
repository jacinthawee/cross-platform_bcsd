
bool ssl3_ctx_ctrl(int param_1,int param_2,int param_3,RSA *param_4)

{
  long lVar1;
  RSA_METHOD *pRVar2;
  ENGINE *pEVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  bool bVar7;
  size_t sVar8;
  DH *dh;
  RSA *pRVar9;
  EC_KEY *key;
  _STACK *st;
  char *pcVar10;
  int iVar11;
  int iVar12;
  
  iVar11 = *(int *)(param_1 + 0xb0);
  switch(param_2) {
  default:
    goto switchD_080a3efa_caseD_0;
  case 1:
    if (*(int *)(iVar11 + 0x18) == 0) {
      if (*(EVP_PKEY **)(iVar11 + 0x34) != (EVP_PKEY *)0x0) {
        iVar11 = EVP_PKEY_size(*(EVP_PKEY **)(iVar11 + 0x34));
        return 0x40 < iVar11;
      }
      goto LAB_080a3f55;
    }
    goto switchD_080a3efa_caseD_0;
  case 2:
    if ((param_4 != (RSA *)0x0) && (pRVar9 = RSAPrivateKey_dup(param_4), pRVar9 != (RSA *)0x0)) {
      if (*(RSA **)(iVar11 + 0x18) != (RSA *)0x0) {
        RSA_free(*(RSA **)(iVar11 + 0x18));
      }
      *(RSA **)(iVar11 + 0x18) = pRVar9;
      return true;
    }
    iVar12 = 0xd7f;
    iVar11 = 4;
    goto LAB_080a3f17;
  case 3:
    dh = DHparams_dup((DH *)param_4);
    if (dh != (DH *)0x0) {
      if (((*(byte *)(param_1 + 0xa6) & 0x10) == 0) && (iVar12 = DH_generate_key(dh), iVar12 == 0))
      {
        ERR_put_error(0x14,0x85,5,"s3_lib.c",0xda1);
        DH_free(dh);
        return false;
      }
      if (*(DH **)(iVar11 + 0x20) != (DH *)0x0) {
        DH_free(*(DH **)(iVar11 + 0x20));
      }
      *(DH **)(iVar11 + 0x20) = dh;
      return true;
    }
    iVar12 = 0xd9a;
    iVar11 = 5;
    goto LAB_080a3f17;
  case 4:
    if (param_4 == (RSA *)0x0) {
      iVar12 = 0xdba;
      iVar11 = 0x2b;
    }
    else {
      key = EC_KEY_dup((EC_KEY *)param_4);
      if (key == (EC_KEY *)0x0) {
        iVar12 = 0xdc0;
        iVar11 = 0x10;
      }
      else {
        if (((*(byte *)(param_1 + 0xa6) & 8) != 0) ||
           (iVar12 = EC_KEY_generate_key(key), iVar12 != 0)) {
          if (*(EC_KEY **)(iVar11 + 0x28) != (EC_KEY *)0x0) {
            EC_KEY_free(*(EC_KEY **)(iVar11 + 0x28));
          }
          *(EC_KEY **)(iVar11 + 0x28) = key;
          return true;
        }
        EC_KEY_free(key);
        iVar12 = 0xdc8;
        iVar11 = 0x2b;
      }
    }
    goto LAB_080a3f17;
  case 5:
    iVar12 = 0xd8d;
    iVar11 = 0x42;
    goto LAB_080a3f17;
  case 6:
    iVar12 = 0xdae;
    iVar11 = 0x42;
    goto LAB_080a3f17;
  case 7:
    iVar12 = 0xdd7;
    iVar11 = 0x42;
    goto LAB_080a3f17;
  case 0xe:
    st = *(_STACK **)(param_1 + 0x94);
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *(_STACK **)(param_1 + 0x94) = st;
      if (st == (_STACK *)0x0) goto switchD_080a3efa_caseD_0;
    }
    sk_push(st,param_4);
    bVar7 = true;
    break;
  case 0x36:
    *(RSA **)(param_1 + 0x104) = param_4;
    bVar7 = true;
    break;
  case 0x3a:
  case 0x3b:
    if (param_4 == (RSA *)0x0) {
      return (bool)0x30;
    }
    if (param_3 == 0x30) {
      if (param_2 != 0x3b) {
        lVar1 = *(long *)(param_1 + 0x10c);
        pRVar2 = *(RSA_METHOD **)(param_1 + 0x110);
        pEVar3 = *(ENGINE **)(param_1 + 0x114);
        param_4->pad = *(int *)(param_1 + 0x108);
        param_4->version = lVar1;
        param_4->meth = pRVar2;
        param_4->engine = pEVar3;
        pBVar4 = *(BIGNUM **)(param_1 + 0x11c);
        pBVar5 = *(BIGNUM **)(param_1 + 0x120);
        pBVar6 = *(BIGNUM **)(param_1 + 0x124);
        param_4->n = *(BIGNUM **)(param_1 + 0x118);
        param_4->e = pBVar4;
        param_4->d = pBVar5;
        param_4->p = pBVar6;
        pBVar4 = *(BIGNUM **)(param_1 + 0x128);
        pBVar5 = *(BIGNUM **)(param_1 + 300);
        pBVar6 = *(BIGNUM **)(param_1 + 0x130);
        param_4->iqmp = *(BIGNUM **)(param_1 + 0x134);
        param_4->q = pBVar4;
        param_4->dmp1 = pBVar5;
        param_4->dmq1 = pBVar6;
        return true;
      }
      lVar1 = param_4->version;
      pRVar2 = param_4->meth;
      pEVar3 = param_4->engine;
      *(int *)(param_1 + 0x108) = param_4->pad;
      *(long *)(param_1 + 0x10c) = lVar1;
      *(RSA_METHOD **)(param_1 + 0x110) = pRVar2;
      *(ENGINE **)(param_1 + 0x114) = pEVar3;
      pBVar4 = param_4->e;
      pBVar5 = param_4->d;
      pBVar6 = param_4->p;
      *(BIGNUM **)(param_1 + 0x118) = param_4->n;
      *(BIGNUM **)(param_1 + 0x11c) = pBVar4;
      *(BIGNUM **)(param_1 + 0x120) = pBVar5;
      *(BIGNUM **)(param_1 + 0x124) = pBVar6;
      pBVar4 = param_4->q;
      pBVar5 = param_4->dmp1;
      pBVar6 = param_4->dmq1;
      *(BIGNUM **)(param_1 + 0x134) = param_4->iqmp;
      *(BIGNUM **)(param_1 + 0x128) = pBVar4;
      *(BIGNUM **)(param_1 + 300) = pBVar5;
      *(BIGNUM **)(param_1 + 0x130) = pBVar6;
      return true;
    }
    iVar12 = 0xde8;
    iVar11 = 0x145;
LAB_080a3f17:
    ERR_put_error(0x14,0x85,iVar11,"s3_lib.c",iVar12);
switchD_080a3efa_caseD_0:
    bVar7 = false;
    break;
  case 0x40:
    *(RSA **)(param_1 + 0x140) = param_4;
    bVar7 = true;
    break;
  case 0x4e:
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    *(RSA **)(param_1 + 0x164) = param_4;
    bVar7 = true;
    break;
  case 0x4f:
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    if (*(void **)(param_1 + 0x174) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x174));
    }
    *(undefined4 *)(param_1 + 0x174) = 0;
    if (param_4 != (RSA *)0x0) {
      sVar8 = strlen((char *)param_4);
      if ((sVar8 < 0x100) && (*(char *)&param_4->pad != '\0')) {
        pcVar10 = BUF_strdup((char *)param_4);
        *(char **)(param_1 + 0x174) = pcVar10;
        if (pcVar10 != (char *)0x0) goto LAB_080a3f55;
        iVar12 = 0xe14;
        iVar11 = 0x44;
      }
      else {
        iVar12 = 0xe0f;
        iVar11 = 0x165;
      }
      goto LAB_080a3f17;
    }
    goto LAB_080a3f55;
  case 0x50:
    *(int *)(param_1 + 0x19c) = param_3;
    bVar7 = true;
    break;
  case 0x51:
    *(code **)(param_1 + 0x170) = srp_password_from_info_cb;
    *(RSA **)(param_1 + 0x198) = param_4;
    bVar7 = true;
    break;
  case 0x52:
    param_4->pad = *(int *)(param_1 + 0x94);
    bVar7 = true;
    break;
  case 0x53:
    if (*(_STACK **)(param_1 + 0x94) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(param_1 + 0x94),X509_free);
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
LAB_080a3f55:
    bVar7 = true;
  }
  return bVar7;
}

