
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar5 = *(uint *)(iVar1 + 0x10);
  if ((uVar5 & 0x2c) != 0) {
    return 1;
  }
  uVar8 = *(uint *)(iVar1 + 0xc);
  if ((uVar8 & 0x100) != 0) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x82,0x44,"s3_clnt.c",0xc71);
    return 0;
  }
  if (*(int *)(iVar1 + 4) == 5) {
    iVar1 = (*(code *)PTR_ssl_check_srvr_ecc_cert_and_alg_006a91d4)
                      (*(undefined4 *)(iVar1 + 0x48),param_1);
    if (iVar1 != 0) {
      return 1;
    }
    uVar4 = 0x130;
    uVar2 = 0xc85;
  }
  else {
    iVar6 = *(int *)(iVar1 + 0x6c);
    iVar7 = *(int *)(iVar1 + 0x70);
    iVar1 = iVar1 + *(int *)(iVar1 + 4) * 0xc;
    uVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(*(undefined4 *)(iVar1 + 0xc));
    uVar3 = (*(code *)PTR_X509_certificate_type_006a914c)(*(undefined4 *)(iVar1 + 0xc),uVar2);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar2);
    if (((uVar5 & 1) == 0) || ((uVar3 & 0x11) == 0x11)) {
      if (((uVar5 & 2) == 0) || ((uVar3 & 0x12) == 0x12)) {
        if ((((uVar8 & 1) == 0) || ((uVar3 & 0x21) == 0x21)) || (iVar6 != 0)) {
          if ((((uVar8 & 8) == 0) || ((uVar3 & 0x44) == 0x44)) || (iVar7 != 0)) {
            if (((uVar8 & 2) == 0) || ((uVar3 & 0x104) == 0x104)) {
              if (((uVar8 & 4) == 0) || ((uVar3 & 0x204) == 0x204)) {
                if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 2) == 0) {
                  return 1;
                }
                if ((uVar3 & 0x1000) != 0) {
                  return 1;
                }
                if ((uVar8 & 1) == 0) {
                  if ((uVar8 & 0xe) == 0) {
                    uVar4 = 0xfa;
                    uVar2 = 0xcd8;
                  }
                  else {
                    if (iVar7 != 0) {
                      iVar1 = (*(code *)PTR_DH_size_006a91d8)(iVar7);
                      iVar6 = 0x400;
                      if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) != 0) {
                        iVar6 = 0x200;
                      }
                      if (iVar1 << 3 <= iVar6) {
                        return 1;
                      }
                    }
                    uVar4 = 0xa6;
                    uVar2 = 0xcd1;
                  }
                }
                else {
                  if (iVar6 != 0) {
                    iVar1 = (*(code *)PTR_RSA_size_006a8730)(iVar6);
                    iVar6 = 0x400;
                    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) != 0) {
                      iVar6 = 0x200;
                    }
                    if (iVar1 << 3 <= iVar6) {
                      return 1;
                    }
                  }
                  uVar4 = 0xa7;
                  uVar2 = 0xcc5;
                }
              }
              else {
                uVar4 = 0xa2;
                uVar2 = 0xcb7;
              }
            }
            else {
              uVar4 = 0xa4;
              uVar2 = 0xcb1;
            }
          }
          else {
            uVar4 = 0xa3;
            uVar2 = 0xcac;
          }
        }
        else {
          uVar4 = 0xa9;
          uVar2 = 0xca4;
        }
      }
      else {
        uVar4 = 0xa5;
        uVar2 = 0xc9c;
      }
    }
    else {
      uVar4 = 0xaa;
      uVar2 = 0xc96;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x82,uVar4,"s3_clnt.c",uVar2);
  ssl3_send_alert(param_1,2,0x28);
  return 0;
}

