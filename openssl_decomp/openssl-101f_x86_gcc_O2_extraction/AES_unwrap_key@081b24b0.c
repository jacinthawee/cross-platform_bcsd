
/* WARNING: Could not reconcile some variable overlaps */

int AES_unwrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  uint __n;
  uint uVar1;
  uint uVar2;
  undefined8 *__s2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int in_GS_OFFSET;
  int local_48;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  __n = inlen - 8;
  if (((__n & 7) == 0) && (7 < __n)) {
    local_2c = *(uint *)(in + 4);
    local_30 = *(undefined4 *)in;
    uVar4 = (__n >> 3) * 6;
    memcpy(out,in + 8,__n);
    local_48 = 6;
    do {
      uVar6 = 0;
      puVar5 = (undefined4 *)(out + (inlen - 0x10));
      do {
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
        local_28 = *puVar5;
        uVar6 = uVar6 + 8;
        uVar4 = uVar4 - 1;
        local_24 = puVar5[1];
        AES_decrypt((uchar *)&local_30,(uchar *)&local_30,key);
        *puVar5 = local_28;
        puVar5[1] = local_24;
        puVar5 = puVar5 + -2;
      } while (uVar6 < __n);
      local_48 = local_48 + -1;
    } while (local_48 != 0);
    __s2 = &default_iv;
    if (iv != (uchar *)0x0) {
      __s2 = (undefined8 *)iv;
    }
    iVar3 = memcmp(&local_30,__s2,8);
    uVar4 = __n;
    if (iVar3 != 0) {
      uVar4 = 0;
      OPENSSL_cleanse(out,__n);
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

