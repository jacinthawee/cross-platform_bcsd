
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  EVP_PKEY *pkey;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar5 = *(uint *)(iVar4 + 0x10);
  uVar6 = *(uint *)(iVar4 + 0xc);
  if ((uVar5 & 0x2c) != 0) {
    return 1;
  }
  if ((int)(uVar6 << 0x17) < 0) {
    return 1;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar4 == 0) {
    ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",0xcfe);
    return 0;
  }
  iVar8 = *(int *)(iVar4 + 0x6c);
  iVar7 = *(int *)(iVar4 + 0x70);
  if (*(int *)(iVar4 + 4) == 5) {
    iVar4 = ssl_check_srvr_ecc_cert_and_alg(*(undefined4 *)(iVar4 + 0x48),param_1);
    if (iVar4 != 0) {
      return 1;
    }
    ERR_put_error(0x14,0x82,0x130,"s3_clnt.c",0xd0f);
    uVar3 = 0x28;
    goto LAB_0004abe8;
  }
  iVar4 = iVar4 + *(int *)(iVar4 + 4) * 0xc;
  pkey = X509_get_pubkey(*(X509 **)(iVar4 + 0xc));
  iVar1 = EVP_PKEY_bits(pkey);
  uVar2 = X509_certificate_type(*(X509 **)(iVar4 + 0xc),pkey);
  EVP_PKEY_free(pkey);
  if (((int)(uVar5 << 0x1f) < 0) && ((uVar2 & 0x11) != 0x11)) {
    ERR_put_error(0x14,0x82,0xaa,"s3_clnt.c",0xd1e);
    uVar3 = 0x28;
    goto LAB_0004abe8;
  }
  if (((int)(uVar5 << 0x1e) < 0) && ((uVar2 & 0x12) != 0x12)) {
    ERR_put_error(0x14,0x82,0xa5,"s3_clnt.c",0xd24);
    uVar3 = 0x28;
    goto LAB_0004abe8;
  }
  if ((uVar6 & 1) == 0) {
LAB_0004ac70:
    uVar5 = uVar6 & 8;
    if ((uVar5 == 0) || (iVar7 != 0)) {
      if (((int)(uVar6 << 0x1e) < 0) && ((uVar2 & 0x104) != 0x104)) {
        ERR_put_error(0x14,0x82,0xa4,"s3_clnt.c",0xd48);
        uVar3 = 0x28;
        goto LAB_0004abe8;
      }
      if (((int)(uVar6 << 0x1d) < 0) && ((uVar2 & 0x204) != 0x204)) {
        ERR_put_error(0x14,0x82,0xa2,"s3_clnt.c",0xd4e);
        uVar3 = 0x28;
        goto LAB_0004abe8;
      }
      if (uVar5 == 0) {
        uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
        if (-1 < (int)(uVar2 << 0x1e)) {
          return 1;
        }
LAB_0004ace2:
        if ((uVar2 & 8) == 0) {
          iVar4 = 0x400;
        }
        else {
          iVar4 = 0x200;
        }
        if (iVar1 <= iVar4) {
          return 1;
        }
        if ((uVar6 & 1) == 0) {
          if (uVar5 == 0) {
            if ((uVar6 & 6) == 0) {
              ERR_put_error(0x14,0x82,0xfa,"s3_clnt.c",0xd84);
              uVar3 = 0x28;
              goto LAB_0004abe8;
            }
            iVar4 = 0xd7e;
          }
          else {
            iVar4 = BN_num_bits(*(BIGNUM **)(iVar7 + 8));
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
              iVar7 = 0x400;
            }
            else {
              iVar7 = 0x200;
            }
            if (iVar4 <= iVar7) {
              return 1;
            }
            iVar4 = 0xd77;
          }
          ERR_put_error(0x14,0x82,0xa6,"s3_clnt.c",iVar4);
          uVar3 = 0x3c;
        }
        else if (iVar8 == 0) {
          ERR_put_error(0x14,0x82,0xa7,"s3_clnt.c",0xd64);
          uVar3 = 0x28;
        }
        else {
          iVar4 = BN_num_bits(*(BIGNUM **)(iVar8 + 0x10));
          if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
            iVar7 = 0x400;
          }
          else {
            iVar7 = 0x200;
          }
          if (iVar4 <= iVar7) {
            return 1;
          }
          ERR_put_error(0x14,0x82,0xa7,"s3_clnt.c",0xd6b);
          uVar3 = 0x3c;
        }
      }
      else {
        iVar4 = BN_num_bits(*(BIGNUM **)(iVar7 + 8));
        uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
        if ((int)(uVar2 << 0x1e) < 0) {
          if (0x1ff < iVar4) goto LAB_0004ace2;
        }
        else if (0x3ff < iVar4) {
          return 1;
        }
        ERR_put_error(0x14,0x82,0x174,"s3_clnt.c",0xd58);
        uVar3 = 0x28;
      }
      goto LAB_0004abe8;
    }
    iVar4 = 0xd43;
  }
  else {
    uVar5 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
    if (-1 < (int)(uVar5 << 0x1e)) {
      if ((uVar2 & 0x21) != 0x21) {
        iVar4 = 0xd2d;
LAB_0004ad74:
        ERR_put_error(0x14,0x82,0xa9,"s3_clnt.c",iVar4);
        uVar3 = 0x28;
        goto LAB_0004abe8;
      }
      goto LAB_0004ac70;
    }
    if ((uVar5 & 8) == 0) {
      iVar4 = 0x400;
    }
    else {
      iVar4 = 0x200;
    }
    if (iVar4 < iVar1) goto LAB_0004ac70;
    if ((uVar2 & 0x21) != 0x21) {
      iVar4 = 0xd33;
      goto LAB_0004ad74;
    }
    if (iVar8 == 0) goto LAB_0004ac70;
    iVar4 = 0xd39;
  }
  ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",iVar4);
  uVar3 = 0x50;
LAB_0004abe8:
  ssl3_send_alert(param_1,2,uVar3);
  return 0;
}

