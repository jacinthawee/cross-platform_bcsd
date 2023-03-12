
void tls1_generate_master_secret(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint *__s;
  int iVar7;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  bool bVar11;
  int local_64;
  int local_60;
  uint local_5c [4];
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  iVar6 = 0;
  local_2c = __stack_chk_guard;
  uVar1 = ssl_get_algorithm2();
  iVar3 = *(int *)(param_1 + 0x58);
  iVar8 = 0;
  iVar7 = *(int *)(param_1 + 0xc0);
  __s = (uint *)(iVar7 + 0x14);
  while (iVar2 = ssl_get_handshake_digest(iVar8,&local_64,&local_60), iVar2 != 0) {
    iVar8 = iVar8 + 1;
    if ((uVar1 & local_64 << 10) != 0) {
      iVar6 = iVar6 + 1;
    }
  }
  if (iVar6 == 0) {
    ERR_put_error(0x14,0x11c,0x44,"t1_enc.c",0x10a);
  }
  else {
    iVar8 = __aeabi_idiv(param_4,iVar6);
    if (iVar6 == 1) {
      param_4 = 0;
    }
    puVar9 = (uint *)(iVar7 + 0x18);
    memset(__s,0,0x30);
    puVar4 = local_5c + 1;
    bVar11 = __s <= puVar4;
    bVar10 = puVar4 == __s;
    if (bVar11 && !bVar10) {
      bVar11 = local_5c <= puVar9;
      bVar10 = puVar9 == local_5c;
    }
    if (!bVar11 || bVar10) {
      puVar4 = (uint *)0x1;
    }
    if (bVar11 && !bVar10) {
      puVar4 = (uint *)0x0;
    }
    while (iVar6 = ssl_get_handshake_digest(iVar2,&local_64,&local_60), iVar6 != 0) {
      if ((uVar1 & local_64 << 10) != 0) {
        if (local_60 == 0) {
          ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x115);
          break;
        }
        iVar6 = tls1_P_hash_constprop_3
                          (local_60,param_3,iVar8 + (param_4 & 1),"master secret",0xd,iVar3 + 0xc0,
                           0x20,0,0,iVar3 + 0xa0,0x20,local_5c,0x30);
        if (iVar6 == 0) break;
        param_3 = param_3 + iVar8;
        puVar5 = puVar4;
        if (puVar4 == (uint *)0x0) {
          do {
            *(byte *)((int)__s + (int)puVar5) =
                 *(byte *)((int)__s + (int)puVar5) ^ *(byte *)((int)local_5c + (int)puVar5);
            puVar5 = (uint *)((int)puVar5 + 1);
          } while (puVar5 != (uint *)0x30);
        }
        else {
          *__s = local_5c[0] ^ *__s;
          *puVar9 = local_5c[1] ^ *puVar9;
          *(uint *)(iVar7 + 0x1c) = local_5c[2] ^ *(uint *)(iVar7 + 0x1c);
          *(uint *)(iVar7 + 0x20) = local_5c[3] ^ *(uint *)(iVar7 + 0x20);
          *(uint *)(iVar7 + 0x24) = local_4c ^ *(uint *)(iVar7 + 0x24);
          *(uint *)(iVar7 + 0x28) = local_48 ^ *(uint *)(iVar7 + 0x28);
          *(uint *)(iVar7 + 0x2c) = local_44 ^ *(uint *)(iVar7 + 0x2c);
          *(uint *)(iVar7 + 0x30) = local_40 ^ *(uint *)(iVar7 + 0x30);
          *(uint *)(iVar7 + 0x34) = local_3c ^ *(uint *)(iVar7 + 0x34);
          *(uint *)(iVar7 + 0x38) = local_38 ^ *(uint *)(iVar7 + 0x38);
          *(uint *)(iVar7 + 0x3c) = local_34 ^ *(uint *)(iVar7 + 0x3c);
          *(uint *)(iVar7 + 0x40) = local_30 ^ *(uint *)(iVar7 + 0x40);
        }
      }
      iVar2 = iVar2 + 1;
    }
  }
  OPENSSL_cleanse(local_5c,0x30);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0x30);
  }
  return;
}
