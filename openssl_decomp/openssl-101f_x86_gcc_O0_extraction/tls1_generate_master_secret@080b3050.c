
undefined4 tls1_generate_master_secret(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int in_GS_OFFSET;
  byte bVar9;
  int local_58;
  int local_54;
  uint local_50 [4];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  bVar9 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = *(int *)(param_1 + 0x58);
  iVar3 = *(int *)(param_1 + 0xc0);
  puVar1 = (uint *)(iVar3 + 0x14);
  uVar4 = ssl_get_algorithm2(param_1);
  iVar7 = 0;
  while (iVar5 = ssl_get_handshake_digest(iVar7,&local_58,&local_54), iVar5 != 0) {
    iVar7 = iVar7 + 1;
  }
  puVar8 = (undefined4 *)(iVar3 + 0x18U & 0xfffffffc);
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined4 *)(iVar3 + 0x40) = 0;
  uVar6 = (uint)((int)puVar1 + (0x30 - (int)puVar8)) >> 2;
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar8 = 0;
    puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
  }
  do {
    iVar7 = ssl_get_handshake_digest(iVar5,&local_58,&local_54);
    if (iVar7 == 0) {
LAB_080b3281:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return 0x30;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if ((uVar4 & local_58 << 10) != 0) {
      if (local_54 == 0) {
        ERR_put_error(0x14,0x11c,0x146,"t1_enc.c",0x114);
        goto LAB_080b3281;
      }
      iVar7 = tls1_P_hash_constprop_2
                        ("master secret",0xd,iVar2 + 0xc0,0x20,0,0,iVar2 + 0xa0,0x20,local_50,0x30);
      if (iVar7 == 0) goto LAB_080b3281;
      if (puVar1 < local_50 + 1 && local_50 < (uint *)(iVar3 + 0x18U) || ((uint)puVar1 & 3) != 0) {
        iVar7 = 0;
        do {
          *(byte *)((int)puVar1 + iVar7) =
               *(byte *)((int)puVar1 + iVar7) ^ *(byte *)((int)local_50 + iVar7);
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x30);
      }
      else {
        *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) ^ local_50[0];
        *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) ^ local_50[1];
        *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) ^ local_50[2];
        *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) ^ local_50[3];
        *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) ^ local_40;
        *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ local_3c;
        *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) ^ local_38;
        *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) ^ local_34;
        *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) ^ local_30;
        *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) ^ local_2c;
        *(uint *)(iVar3 + 0x3c) = *(uint *)(iVar3 + 0x3c) ^ local_28;
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) ^ local_24;
      }
    }
    iVar5 = iVar5 + 1;
  } while( true );
}

