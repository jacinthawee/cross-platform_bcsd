
void BF_ecb_encrypt(uchar *in,uchar *out,BF_KEY *key,int enc)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_1c;
  uint local_18;
  uint *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(uint *)in;
  local_18 = *(uint *)(in + 4);
  local_14 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  if (enc == 0) {
    BF_decrypt(&local_1c,key);
  }
  else {
    BF_encrypt(&local_1c,key);
  }
  out[3] = (uchar)local_1c;
  out[7] = (uchar)local_18;
  *out = (uchar)(local_1c >> 0x18);
  out[1] = (uchar)(local_1c >> 0x10);
  puVar2 = (uint *)(local_18 >> 0x10);
  out[2] = (uchar)(local_1c >> 8);
  out[4] = (uchar)(local_18 >> 0x18);
  out[5] = (uchar)(local_18 >> 0x10);
  out[6] = (uchar)(local_18 >> 8);
  if (local_14 == *(uint **)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar7 = *local_14 ^ *puVar2;
  uVar6 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          local_14[1] ^ puVar2[1];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[2];
  uVar6 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[3];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[4];
  uVar6 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[5];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[6];
  uVar9 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[7];
  uVar6 = (*(int *)((int)puVar2 + (uVar9 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar9 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar9 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar9 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[8];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar9 ^ puVar2[9];
  uVar6 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[10];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[0xb];
  uVar6 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[0xc];
  uVar8 = puVar2[0x10];
  uVar7 = (*(int *)((int)puVar2 + (uVar6 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar6 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar6 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar6 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[0xd];
  uVar9 = (*(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar7 & 0xff) + 0x312] ^
          uVar6 ^ puVar2[0xe];
  uVar7 = (*(int *)((int)puVar2 + (uVar9 >> 0xe & 0x3fc) + 0x448) +
           *(int *)((int)puVar2 + (uVar9 >> 0x16 & 0x3fc) + 0x48) ^
          *(uint *)((int)puVar2 + (uVar9 >> 6 & 0x3fc) + 0x848)) + puVar2[(uVar9 & 0xff) + 0x312] ^
          uVar7 ^ puVar2[0xf];
  iVar5 = *(int *)((int)puVar2 + (uVar7 >> 0x16 & 0x3fc) + 0x48);
  iVar3 = *(int *)((int)puVar2 + (uVar7 >> 0xe & 0x3fc) + 0x448);
  uVar4 = *(uint *)((int)puVar2 + (uVar7 >> 6 & 0x3fc) + 0x848);
  uVar6 = puVar2[(uVar7 & 0xff) + 0x312];
  *local_14 = uVar7 ^ puVar2[0x11];
  local_14[1] = (iVar3 + iVar5 ^ uVar4) + uVar6 ^ uVar9 ^ uVar8;
  return;
}

