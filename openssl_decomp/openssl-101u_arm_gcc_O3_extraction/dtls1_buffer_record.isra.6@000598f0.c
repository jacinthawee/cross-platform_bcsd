
undefined4 dtls1_buffer_record_isra_6(int param_1,pqueue *param_2,uchar *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *data;
  pitem *item;
  pitem *ppVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int line;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar1 = pqueue_size(*param_2);
  if (iVar1 < 100) {
    data = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xe6);
    item = pitem_new(param_3,data);
    if (data == (undefined4 *)0x0 || item == (pitem *)0x0) {
      if (data != (undefined4 *)0x0) {
        CRYPTO_free(data);
      }
      if (item != (pitem *)0x0) {
        pitem_free(item);
      }
      ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0xee);
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x58);
      uVar2 = *(undefined4 *)(param_1 + 0x50);
      *data = *(undefined4 *)(param_1 + 0x4c);
      data[1] = uVar2;
      uVar5 = *(undefined4 *)(iVar1 + 0xf8);
      uVar2 = *(undefined4 *)(iVar1 + 0xf0);
      uVar4 = *(undefined4 *)(iVar1 + 0xf4);
      data[2] = *(undefined4 *)(iVar1 + 0xec);
      data[3] = uVar2;
      data[4] = uVar4;
      data[5] = uVar5;
      iVar1 = *(int *)(param_1 + 0x58);
      puVar6 = (undefined4 *)(iVar1 + 0x10c);
      puVar8 = data + 6;
      do {
        puVar7 = puVar6 + 4;
        uVar5 = puVar6[1];
        puVar9 = puVar8 + 4;
        uVar2 = puVar6[2];
        uVar4 = puVar6[3];
        *puVar8 = *puVar6;
        puVar8[1] = uVar5;
        puVar8[2] = uVar2;
        puVar8[3] = uVar4;
        puVar6 = puVar7;
        puVar8 = puVar9;
      } while (puVar7 != (undefined4 *)(iVar1 + 300));
      *puVar9 = *puVar7;
      iVar1 = *(int *)(param_1 + 0x58);
      item->data = data;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      memset((void *)(iVar1 + 0xec),0,0x10);
      memset((void *)(*(int *)(param_1 + 0x58) + 0x10c),0,0x24);
      iVar1 = ssl3_setup_buffers(param_1);
      line = 0x109;
      if (iVar1 != 0) {
        ppVar3 = pqueue_insert(*param_2,item);
        if (ppVar3 != (pitem *)0x0) {
          return 1;
        }
        line = 0x113;
      }
      ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",line);
      if ((void *)data[2] != (void *)0x0) {
        CRYPTO_free((void *)data[2]);
      }
      CRYPTO_free(data);
      pitem_free(item);
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

