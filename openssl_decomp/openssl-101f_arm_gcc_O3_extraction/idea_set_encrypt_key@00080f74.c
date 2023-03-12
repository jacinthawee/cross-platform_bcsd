
void idea_set_encrypt_key(uchar *key,IDEA_KEY_SCHEDULE *ks)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  bVar1 = *key;
  ks->data[0] = (uint)bVar1 << 8;
  ks->data[0] = (uint)CONCAT11(bVar1,key[1]);
  bVar1 = key[2];
  ks->data[1] = (uint)bVar1 << 8;
  ks->data[1] = (uint)CONCAT11(bVar1,key[3]);
  bVar1 = key[4];
  ks->data[2] = (uint)bVar1 << 8;
  ks->data[2] = (uint)CONCAT11(bVar1,key[5]);
  bVar1 = key[6];
  ks->data[3] = (uint)bVar1 << 8;
  ks->data[3] = (uint)CONCAT11(bVar1,key[7]);
  bVar1 = key[8];
  ks->data[4] = (uint)bVar1 << 8;
  ks->data[4] = (uint)CONCAT11(bVar1,key[9]);
  bVar1 = key[10];
  ks->data[5] = (uint)bVar1 << 8;
  ks->data[5] = (uint)CONCAT11(bVar1,key[0xb]);
  bVar1 = key[0xc];
  ks->data[1][0] = (uint)bVar1 << 8;
  ks->data[1][0] = (uint)CONCAT11(bVar1,key[0xd]);
  bVar1 = key[0xe];
  ks->data[1][1] = (uint)bVar1 << 8;
  ks->data[1][1] = (uint)CONCAT11(bVar1,key[0xf]);
  puVar3 = (uint *)ks;
  puVar6 = ks->data[1] + 2;
  while( true ) {
    uVar2 = puVar3[1];
    uVar4 = puVar3[2];
    *puVar6 = (uVar2 << 9 | uVar4 >> 7) & 0xffff;
    uVar5 = puVar3[3];
    puVar6[1] = (uVar4 << 9 | uVar5 >> 7) & 0xffff;
    uVar4 = puVar3[4];
    puVar6[2] = (uVar5 << 9 | uVar4 >> 7) & 0xffff;
    uVar5 = puVar3[5];
    puVar6[3] = (uVar4 << 9 | uVar5 >> 7) & 0xffff;
    uVar4 = puVar3[6];
    puVar6[4] = (uVar5 << 9 | uVar4 >> 7) & 0xffff;
    uVar5 = puVar3[7];
    puVar6[5] = (uVar4 << 9 | uVar5 >> 7) & 0xffff;
    uVar4 = *puVar3;
    if ((uint (*) [6])puVar6 == ks->data[8]) break;
    puVar6[6] = (uVar5 << 9 | uVar4 >> 7) & 0xffff;
    puVar6[7] = (uVar4 << 9 | uVar2 >> 7) & 0xffff;
    puVar3 = puVar3 + 8;
    puVar6 = puVar6 + 8;
  }
  return;
}

