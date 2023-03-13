
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  uint uVar1;
  int iVar2;
  EVP_PKEY *pkey;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar6 = *(uint *)(iVar7 + 0x10);
  if ((uVar6 & 0x2c) != 0) {
    return 1;
  }
  uVar1 = *(uint *)(iVar7 + 0xc);
  if ((uVar1 & 0x100) != 0) {
    return 1;
  }
  iVar7 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar7 == 0) {
    ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",0xcfe);
    return 0;
  }
  if (*(int *)(iVar7 + 4) == 5) {
    iVar7 = ssl_check_srvr_ecc_cert_and_alg(*(undefined4 *)(iVar7 + 0x48),param_1);
    if (iVar7 != 0) {
      return 1;
    }
    iVar8 = 0xd0f;
    iVar7 = 0x130;
  }
  else {
    iVar8 = *(int *)(iVar7 + 0x6c);
    iVar2 = *(int *)(iVar7 + 0x70);
    iVar7 = iVar7 + *(int *)(iVar7 + 4) * 0xc;
    pkey = X509_get_pubkey(*(X509 **)(iVar7 + 0xc));
    iVar3 = EVP_PKEY_bits(pkey);
    uVar4 = X509_certificate_type(*(X509 **)(iVar7 + 0xc),pkey);
    EVP_PKEY_free(pkey);
    if (((uVar6 & 1) == 0) || ((uVar4 & 0x11) == 0x11)) {
      if (((uVar6 & 2) == 0) || ((uVar4 & 0x12) == 0x12)) {
        if ((uVar1 & 1) == 0) {
LAB_0809e7e0:
          uVar6 = uVar1 & 8;
          if ((uVar6 == 0) || (iVar2 != 0)) {
            if (((uVar1 & 2) == 0) || ((uVar4 & 0x104) == 0x104)) {
              if (((uVar1 & 4) == 0) || ((uVar4 & 0x204) == 0x204)) {
                if (uVar6 == 0) {
                  uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
                  if ((uVar4 & 2) == 0) {
                    return 1;
                  }
LAB_0809e875:
                  if (iVar3 <= (int)((-(uint)((uVar4 & 8) == 0) & 0x200) + 0x200)) {
                    return 1;
                  }
                  if ((uVar1 & 1) == 0) {
                    if (uVar6 == 0) {
                      if ((uVar1 & 6) == 0) {
                        iVar8 = 0xd84;
                        iVar7 = 0xfa;
                        goto LAB_0809e6f8;
                      }
                      iVar7 = 0xd7e;
                    }
                    else {
                      iVar7 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
                      if (iVar7 <= (int)((-(uint)((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) +
                                                                     0x344) + 0x20) & 8) == 0) &
                                         0x200) + 0x200)) {
                        return 1;
                      }
                      iVar7 = 0xd77;
                    }
                    iVar8 = 0xa6;
                  }
                  else {
                    if (iVar8 == 0) {
                      iVar8 = 0xd64;
                      iVar7 = 0xa7;
                      goto LAB_0809e6f8;
                    }
                    iVar7 = BN_num_bits(*(BIGNUM **)(iVar8 + 0x10));
                    if (iVar7 <= (int)((-(uint)((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344
                                                                   ) + 0x20) & 8) == 0) & 0x200) +
                                      0x200)) {
                      return 1;
                    }
                    iVar7 = 0xd6b;
                    iVar8 = 0xa7;
                  }
                  ERR_put_error(0x14,0x82,iVar8,"s3_clnt.c",iVar7);
                  uVar5 = 0x3c;
                  goto LAB_0809e70c;
                }
                iVar7 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
                uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
                if ((uVar4 & 2) == 0) {
                  if (0x3ff < iVar7) {
                    return 1;
                  }
                }
                else if (0x1ff < iVar7) goto LAB_0809e875;
                iVar8 = 0xd58;
                iVar7 = 0x174;
              }
              else {
                iVar8 = 0xd4e;
                iVar7 = 0xa2;
              }
            }
            else {
              iVar8 = 0xd48;
              iVar7 = 0xa4;
            }
            goto LAB_0809e6f8;
          }
          iVar7 = 0xd43;
        }
        else {
          uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
          if ((uVar6 & 2) == 0) {
            if ((uVar4 & 0x21) != 0x21) {
              iVar8 = 0xd2d;
              iVar7 = 0xa9;
              goto LAB_0809e6f8;
            }
            goto LAB_0809e7e0;
          }
          if ((int)((-(uint)((uVar6 & 8) == 0) & 0x200) + 0x200) < iVar3) goto LAB_0809e7e0;
          if ((uVar4 & 0x21) != 0x21) {
            iVar8 = 0xd33;
            iVar7 = 0xa9;
            goto LAB_0809e6f8;
          }
          if (iVar8 == 0) goto LAB_0809e7e0;
          iVar7 = 0xd39;
        }
        ERR_put_error(0x14,0x82,0x44,"s3_clnt.c",iVar7);
        uVar5 = 0x50;
        goto LAB_0809e70c;
      }
      iVar8 = 0xd24;
      iVar7 = 0xa5;
    }
    else {
      iVar8 = 0xd1e;
      iVar7 = 0xaa;
    }
  }
LAB_0809e6f8:
  ERR_put_error(0x14,0x82,iVar7,"s3_clnt.c",iVar8);
  uVar5 = 0x28;
LAB_0809e70c:
  ssl3_send_alert(param_1,2,uVar5);
  return 0;
}

