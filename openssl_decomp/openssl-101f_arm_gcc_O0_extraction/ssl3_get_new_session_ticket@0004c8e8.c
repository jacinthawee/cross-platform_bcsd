
int ssl3_get_new_session_ticket(int param_1)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  EVP_MD *type;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int local_1c [2];
  
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x11e0,0x11e1,0xffffffff,0x4000,local_1c);
  if (local_1c[0] != 0) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x58) + 0x340);
    if (iVar6 == 0x14) {
      iVar2 = 1;
    }
    if (iVar6 == 0x14) {
      *(int *)(*(int *)(param_1 + 0x58) + 0x354) = iVar2;
    }
    else {
      if (iVar6 == 4) {
        if (iVar2 < 6) {
          iVar2 = 0x811;
        }
        else {
          pbVar7 = *(byte **)(param_1 + 0x40);
          iVar6 = *(int *)(param_1 + 0xc0);
          bVar1 = *pbVar7;
          *(uint *)(iVar6 + 0xec) = (uint)bVar1 << 0x18;
          uVar4 = (uint)bVar1 << 0x18 | (uint)pbVar7[1] << 0x10;
          *(uint *)(iVar6 + 0xec) = uVar4;
          uVar4 = uVar4 | (uint)pbVar7[2] << 8;
          *(uint *)(iVar6 + 0xec) = uVar4;
          *(uint *)(iVar6 + 0xec) = uVar4 | pbVar7[3];
          uVar4 = (uint)CONCAT11(pbVar7[4],pbVar7[5]);
          if (uVar4 + 6 == iVar2) {
            if (*(void **)(iVar6 + 0xe4) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar6 + 0xe4));
              iVar6 = *(int *)(param_1 + 0xc0);
              *(undefined4 *)(iVar6 + 0xe8) = 0;
            }
            pvVar3 = CRYPTO_malloc(uVar4,"s3_clnt.c",0x824);
            iVar2 = *(int *)(param_1 + 0xc0);
            *(void **)(iVar6 + 0xe4) = pvVar3;
            pvVar3 = *(void **)(iVar2 + 0xe4);
            if (pvVar3 != (void *)0x0) {
              memcpy(pvVar3,pbVar7 + 6,uVar4);
              iVar2 = *(int *)(param_1 + 0xc0);
              *(uint *)(iVar2 + 0xe8) = uVar4;
              type = EVP_sha256();
              EVP_Digest(pbVar7 + 6,uVar4,(uchar *)(iVar2 + 0x48),(uint *)(iVar2 + 0x44),type,
                         (ENGINE *)0x0);
              return 1;
            }
            ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x827);
            return -1;
          }
          iVar2 = 0x81c;
        }
        ERR_put_error(0x14,0x11b,0x9f,"s3_clnt.c",iVar2);
        uVar5 = 0x32;
      }
      else {
        ERR_put_error(0x14,0x11b,0x72,"s3_clnt.c",0x80a);
        uVar5 = 10;
      }
      ssl3_send_alert(param_1,2,uVar5);
      iVar2 = -1;
    }
  }
  return iVar2;
}

