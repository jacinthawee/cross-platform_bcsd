
int ssl3_get_new_session_ticket(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  void *pvVar4;
  EVP_MD *type;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x11e0,0x11e1,0xffffffff,0x4000,&local_24);
  if (local_24 != 0) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x58) + 0x340);
    if (iVar7 == 0x14) {
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x354) = 1;
      iVar3 = 1;
    }
    else {
      if (iVar7 == 4) {
        if (iVar3 < 6) {
          iVar3 = 0x811;
        }
        else {
          pbVar2 = *(byte **)(param_1 + 0x40);
          iVar7 = *(int *)(param_1 + 0xc0);
          bVar1 = *pbVar2;
          *(uint *)(iVar7 + 0xec) = (uint)bVar1 << 0x18;
          uVar6 = (uint)pbVar2[1] << 0x10 | (uint)bVar1 << 0x18;
          *(uint *)(iVar7 + 0xec) = uVar6;
          uVar6 = (uint)pbVar2[2] << 8 | uVar6;
          *(uint *)(iVar7 + 0xec) = uVar6;
          *(uint *)(iVar7 + 0xec) = uVar6 | pbVar2[3];
          uVar6 = (uint)(ushort)(*(ushort *)(pbVar2 + 4) << 8 | *(ushort *)(pbVar2 + 4) >> 8);
          if (iVar3 == uVar6 + 6) {
            if (*(void **)(iVar7 + 0xe4) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar7 + 0xe4));
              iVar7 = *(int *)(param_1 + 0xc0);
              *(undefined4 *)(iVar7 + 0xe8) = 0;
            }
            pvVar4 = CRYPTO_malloc(uVar6,"s3_clnt.c",0x824);
            *(void **)(iVar7 + 0xe4) = pvVar4;
            pvVar4 = *(void **)(*(int *)(param_1 + 0xc0) + 0xe4);
            if (pvVar4 == (void *)0x0) {
              ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x827);
              iVar3 = -1;
            }
            else {
              memcpy(pvVar4,pbVar2 + 6,uVar6);
              *(uint *)(*(int *)(param_1 + 0xc0) + 0xe8) = uVar6;
              type = EVP_sha256();
              EVP_Digest(pbVar2 + 6,uVar6,(uchar *)(*(int *)(param_1 + 0xc0) + 0x48),
                         (uint *)(*(int *)(param_1 + 0xc0) + 0x44),type,(ENGINE *)0x0);
              iVar3 = 1;
            }
            goto LAB_080a0839;
          }
          iVar3 = 0x81c;
        }
        ERR_put_error(0x14,0x11b,0x9f,"s3_clnt.c",iVar3);
        uVar5 = 0x32;
      }
      else {
        ERR_put_error(0x14,0x11b,0x72,"s3_clnt.c",0x80a);
        uVar5 = 10;
      }
      ssl3_send_alert(param_1,2,uVar5);
      iVar3 = -1;
    }
  }
LAB_080a0839:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

