
pitem * dtls1_buffer_record_isra_6(int param_1,pqueue *param_2,uchar *param_3)

{
  int iVar1;
  undefined4 *data;
  pitem *item;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  pitem *ppVar8;
  undefined4 uVar9;
  
  iVar1 = pqueue_size(*param_2);
  if (iVar1 < 100) {
    data = (undefined4 *)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
    item = pitem_new(param_3,data);
    if (data == (undefined4 *)0x0 || item == (pitem *)0x0) {
      if (data != (undefined4 *)0x0) {
        CRYPTO_free(data);
      }
      if (item != (pitem *)0x0) {
        pitem_free(item);
      }
      ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
      return (pitem *)0x0;
    }
    iVar1 = *(int *)(param_1 + 0x58);
    uVar2 = *(undefined4 *)(param_1 + 0x50);
    *data = *(undefined4 *)(param_1 + 0x4c);
    data[1] = uVar2;
    uVar3 = *(undefined4 *)(iVar1 + 0xf8);
    uVar9 = *(undefined4 *)(iVar1 + 0xf0);
    uVar2 = *(undefined4 *)(iVar1 + 0xf4);
    data[2] = *(undefined4 *)(iVar1 + 0xec);
    data[3] = uVar9;
    data[4] = uVar2;
    data[5] = uVar3;
    iVar1 = *(int *)(param_1 + 0x58);
    puVar4 = data + 6;
    puVar6 = (undefined4 *)(iVar1 + 0x10c);
    do {
      puVar7 = puVar6 + 4;
      uVar3 = puVar6[1];
      puVar5 = puVar4 + 4;
      uVar9 = puVar6[2];
      uVar2 = puVar6[3];
      *puVar4 = *puVar6;
      puVar4[1] = uVar3;
      puVar4[2] = uVar9;
      puVar4[3] = uVar2;
      puVar4 = puVar5;
      puVar6 = puVar7;
    } while (puVar7 != (undefined4 *)(iVar1 + 300));
    *puVar5 = *puVar7;
    item->data = data;
    ppVar8 = pqueue_insert(*param_2,item);
    if (ppVar8 != (pitem *)0x0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      memset((void *)(*(int *)(param_1 + 0x58) + 0xec),0,0x10);
      memset((void *)(*(int *)(param_1 + 0x58) + 0x10c),0,0x24);
      ppVar8 = (pitem *)ssl3_setup_buffers(param_1);
      if (ppVar8 != (pitem *)0x0) {
        return (pitem *)0x1;
      }
      ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0x101);
    }
    CRYPTO_free(data);
    pitem_free(item);
  }
  else {
    ppVar8 = (pitem *)0x0;
  }
  return ppVar8;
}

