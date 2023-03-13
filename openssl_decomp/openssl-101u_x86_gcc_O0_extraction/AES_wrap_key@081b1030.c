
/* WARNING: Could not reconcile some variable overlaps */

int AES_wrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int in_GS_OFFSET;
  int local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((inlen & 7) == 0) && (7 < inlen)) {
    memcpy(out + 8,in,inlen);
    if (iv == (uchar *)0x0) {
      iv = (uchar *)&default_iv;
    }
    local_40 = 6;
    local_30 = *(undefined4 *)iv;
    local_2c = *(uint *)((int)iv + 4);
    uVar4 = 1;
    do {
      uVar5 = 0;
      do {
        local_28 = *(undefined4 *)(out + uVar5 + 8);
        local_24 = *(undefined4 *)(out + uVar5 + 0xc);
        AES_encrypt((uchar *)&local_30,(uchar *)&local_30,key);
        uVar1 = local_2c & 0xffffff;
        uVar2 = (uint)(byte)(local_2c._3_1_ ^ (byte)uVar4) << 0x18;
        local_2c = uVar1 | uVar2;
        if (0xff < uVar4) {
          local_2c._2_1_ = (byte)(uVar1 >> 0x10);
          local_2c._0_3_ = CONCAT12(local_2c._2_1_ ^ (byte)(uVar4 >> 8),(short)uVar1);
          local_2c._1_1_ = (byte)((uint)(uint3)local_2c >> 8);
          local_2c = uVar2 | (uint3)local_2c & 0xffff0000 |
                     (uint)(byte)(local_2c._1_1_ ^ (byte)(uVar4 >> 0x10)) << 8 |
                     (uint)(byte)((byte)uVar1 ^ (byte)(uVar4 >> 0x18));
        }
        uVar4 = uVar4 + 1;
        *(undefined4 *)(out + uVar5 + 8) = local_28;
        *(undefined4 *)(out + uVar5 + 0xc) = local_24;
        uVar5 = uVar5 + 8;
      } while (uVar5 < inlen);
      local_40 = local_40 + -1;
    } while (local_40 != 0);
    *(undefined4 *)out = local_30;
    *(uint *)(out + 4) = local_2c;
    iVar3 = inlen + 8;
  }
  else {
    iVar3 = -1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

