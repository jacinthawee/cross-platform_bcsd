
uchar * SHA224(uchar *d,size_t n,uchar *md)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int in_GS_OFFSET;
  byte bVar6;
  uint local_90 [4];
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined2 uStack_32;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  int local_20;
  
  bVar6 = 0;
  iVar3 = 0x1c;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (md == (uchar *)0x0) {
    md = m_3925;
  }
  puVar5 = local_90;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_90[0] = 0xc1059ed8;
  local_90[1] = 0x367cd507;
  local_90[2] = 0x3070dd17;
  local_90[3] = 0xf70e5939;
  local_80 = 0xffc00b31;
  local_7c = 0x68581511;
  local_78 = 0x64f98fa7;
  local_74 = 0xbefa4fa4;
  local_24 = 0x1c;
  if (n == 0) {
    local_68._0_1_ = 0x80;
    uVar1 = 1;
LAB_080db1ee:
    uVar4 = 0x38 - uVar1;
    puVar2 = (undefined4 *)((int)&local_68 + uVar1);
    if (uVar4 < 4) {
      if ((uVar4 != 0) && (*(undefined *)puVar2 = 0, (uVar4 & 2) != 0)) {
        *(undefined2 *)((int)&local_68 + uVar4 + uVar1 + -2) = 0;
      }
      goto LAB_080db240;
    }
  }
  else {
    SHA256_Update_part_0();
    uVar1 = local_28 + 1;
    *(undefined *)((int)&local_68 + local_28) = 0x80;
    if (uVar1 < 0x39) goto LAB_080db1ee;
    memset((void *)((int)&local_68 + local_28 + 1),0,0x40 - uVar1);
    sha256_block_data_order();
    uVar4 = 0x38;
    puVar2 = &local_68;
  }
  *puVar2 = 0;
  *(undefined4 *)((int)puVar2 + (uVar4 - 4)) = 0;
  uVar1 = (uint)((int)puVar2 + (uVar4 - ((uint)(puVar2 + 1) & 0xfffffffc))) & 0xfffffffc;
  if (3 < uVar1) {
    uVar4 = 0;
    do {
      *(undefined4 *)(((uint)(puVar2 + 1) & 0xfffffffc) + uVar4) = 0;
      uVar4 = uVar4 + 4;
    } while (uVar4 < uVar1);
  }
LAB_080db240:
  local_30 = local_6c >> 0x18 | (local_6c & 0xff0000) >> 8 | (local_6c & 0xff00) << 8 |
             local_6c << 0x18;
  local_2c = local_70 >> 0x18 | (local_70 & 0xff0000) >> 8 | (local_70 & 0xff00) << 8 |
             local_70 << 0x18;
  sha256_block_data_order();
  local_28 = 0;
  puVar2 = &local_68;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar6 * -2 + 1;
  }
  if (local_24 == 0x1c) {
    *(uint *)md = local_90[0] >> 0x18 | (local_90[0] & 0xff0000) >> 8 | (local_90[0] & 0xff00) << 8
                  | local_90[0] << 0x18;
    *(uint *)((int)md + 4) =
         local_90[1] >> 0x18 | (local_90[1] & 0xff0000) >> 8 | (local_90[1] & 0xff00) << 8 |
         local_90[1] << 0x18;
    *(uint *)((int)md + 8) =
         local_90[2] >> 0x18 | (local_90[2] & 0xff0000) >> 8 | (local_90[2] & 0xff00) << 8 |
         local_90[2] << 0x18;
    *(uint *)((int)md + 0xc) =
         local_90[3] >> 0x18 | (local_90[3] & 0xff0000) >> 8 | (local_90[3] & 0xff00) << 8 |
         local_90[3] << 0x18;
    *(uint *)((int)md + 0x10) =
         local_80 >> 0x18 | (local_80 & 0xff0000) >> 8 | (local_80 & 0xff00) << 8 | local_80 << 0x18
    ;
    *(uint *)((int)md + 0x14) =
         local_7c >> 0x18 | (local_7c & 0xff0000) >> 8 | (local_7c & 0xff00) << 8 | local_7c << 0x18
    ;
    *(uint *)((int)md + 0x18) =
         local_78 >> 0x18 | (local_78 & 0xff0000) >> 8 | (local_78 & 0xff00) << 8 | local_78 << 0x18
    ;
  }
  else if (local_24 == 0x20) {
    *(uint *)md = local_90[0] >> 0x18 | (local_90[0] & 0xff0000) >> 8 | (local_90[0] & 0xff00) << 8
                  | local_90[0] << 0x18;
    *(uint *)((int)md + 4) =
         local_90[1] >> 0x18 | (local_90[1] & 0xff0000) >> 8 | (local_90[1] & 0xff00) << 8 |
         local_90[1] << 0x18;
    *(uint *)((int)md + 8) =
         local_90[2] >> 0x18 | (local_90[2] & 0xff0000) >> 8 | (local_90[2] & 0xff00) << 8 |
         local_90[2] << 0x18;
    *(uint *)((int)md + 0xc) =
         local_90[3] >> 0x18 | (local_90[3] & 0xff0000) >> 8 | (local_90[3] & 0xff00) << 8 |
         local_90[3] << 0x18;
    *(uint *)((int)md + 0x10) =
         local_80 >> 0x18 | (local_80 & 0xff0000) >> 8 | (local_80 & 0xff00) << 8 | local_80 << 0x18
    ;
    *(uint *)((int)md + 0x14) =
         local_7c >> 0x18 | (local_7c & 0xff0000) >> 8 | (local_7c & 0xff00) << 8 | local_7c << 0x18
    ;
    *(uint *)((int)md + 0x18) =
         local_78 >> 0x18 | (local_78 & 0xff0000) >> 8 | (local_78 & 0xff00) << 8 | local_78 << 0x18
    ;
    *(uint *)((int)md + 0x1c) =
         local_74 >> 0x18 | (local_74 & 0xff0000) >> 8 | (local_74 & 0xff00) << 8 | local_74 << 0x18
    ;
  }
  else if ((((((local_24 < 0x21) && (uVar1 = local_24 >> 2, uVar1 != 0)) &&
             (*(uint *)md = local_90[0] >> 0x18 | (local_90[0] & 0xff0000) >> 8 |
                            (local_90[0] & 0xff00) << 8 | local_90[0] << 0x18, uVar1 != 1)) &&
            ((*(uint *)((int)md + 4) =
                   local_90[1] >> 0x18 | (local_90[1] & 0xff0000) >> 8 | (local_90[1] & 0xff00) << 8
                   | local_90[1] << 0x18, uVar1 != 2 &&
             (*(uint *)((int)md + 8) =
                   local_90[2] >> 0x18 | (local_90[2] & 0xff0000) >> 8 | (local_90[2] & 0xff00) << 8
                   | local_90[2] << 0x18, uVar1 != 3)))) &&
           ((*(uint *)((int)md + 0xc) =
                  local_90[3] >> 0x18 | (local_90[3] & 0xff0000) >> 8 | (local_90[3] & 0xff00) << 8
                  | local_90[3] << 0x18, uVar1 != 4 &&
            ((*(uint *)((int)md + 0x10) =
                   local_80 >> 0x18 | (local_80 & 0xff0000) >> 8 | (local_80 & 0xff00) << 8 |
                   local_80 << 0x18, uVar1 != 5 &&
             (*(uint *)((int)md + 0x14) =
                   local_7c >> 0x18 | (local_7c & 0xff0000) >> 8 | (local_7c & 0xff00) << 8 |
                   local_7c << 0x18, uVar1 != 6)))))) &&
          (*(uint *)((int)md + 0x18) =
                local_78 >> 0x18 | (local_78 & 0xff0000) >> 8 | (local_78 & 0xff00) << 8 |
                local_78 << 0x18, uVar1 == 8)) {
    *(uint *)((int)md + 0x1c) =
         local_74 >> 0x18 | (local_74 & 0xff0000) >> 8 | (local_74 & 0xff00) << 8 | local_74 << 0x18
    ;
  }
  OPENSSL_cleanse(local_90,0x70);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (uchar *)(uint *)md;
}

