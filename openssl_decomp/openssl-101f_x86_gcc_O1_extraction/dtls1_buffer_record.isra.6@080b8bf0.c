
int __regparm3 dtls1_buffer_record_isra_6(int param_1,pqueue *param_2,uchar *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *data;
  pitem *item;
  pitem *ppVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  
  bVar8 = 0;
  iVar4 = pqueue_size(*param_2);
  if (iVar4 < 100) {
    data = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
    item = pitem_new(param_3,data);
    if ((data == (undefined4 *)0x0) || (item == (pitem *)0x0)) {
      if (data != (undefined4 *)0x0) {
        CRYPTO_free(data);
      }
      if (item != (pitem *)0x0) {
        pitem_free(item);
      }
      ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
      return 0;
    }
    *data = *(undefined4 *)(param_1 + 0x4c);
    data[1] = *(undefined4 *)(param_1 + 0x50);
    iVar4 = *(int *)(param_1 + 0x58);
    uVar1 = *(undefined4 *)(iVar4 + 0xf0);
    uVar2 = *(undefined4 *)(iVar4 + 0xf4);
    uVar3 = *(undefined4 *)(iVar4 + 0xf8);
    data[2] = *(undefined4 *)(iVar4 + 0xec);
    data[4] = uVar2;
    data[5] = uVar3;
    data[3] = uVar1;
    iVar4 = *(int *)(param_1 + 0x58);
    data[6] = *(undefined4 *)(iVar4 + 0x10c);
    data[7] = *(undefined4 *)(iVar4 + 0x110);
    data[8] = *(undefined4 *)(iVar4 + 0x114);
    data[9] = *(undefined4 *)(iVar4 + 0x118);
    data[10] = *(undefined4 *)(iVar4 + 0x11c);
    data[0xb] = *(undefined4 *)(iVar4 + 0x120);
    data[0xc] = *(undefined4 *)(iVar4 + 0x124);
    data[0xd] = *(undefined4 *)(iVar4 + 0x128);
    data[0xe] = *(undefined4 *)(iVar4 + 300);
    item->data = data;
    ppVar5 = pqueue_insert(*param_2,item);
    if (ppVar5 == (pitem *)0x0) {
      CRYPTO_free(data);
      pitem_free(item);
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x58);
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(iVar4 + 0xec) = 0;
      *(undefined4 *)(iVar4 + 0xf0) = 0;
      *(undefined4 *)(iVar4 + 0xf4) = 0;
      *(undefined4 *)(iVar4 + 0xf8) = 0;
      iVar4 = *(int *)(param_1 + 0x58);
      *(undefined4 *)(iVar4 + 0x10c) = 0;
      *(undefined4 *)(iVar4 + 300) = 0;
      puVar7 = (undefined4 *)(iVar4 + 0x110U & 0xfffffffc);
      uVar6 = (iVar4 - (int)puVar7) + 0x130U >> 2;
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
      }
      iVar4 = ssl3_setup_buffers(param_1);
      if (iVar4 == 0) {
        ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0x101);
        CRYPTO_free(data);
        pitem_free(item);
      }
      else {
        iVar4 = 1;
      }
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

