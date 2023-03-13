
void lh_free(_LHASH *lh)

{
  lhash_node_st *plVar1;
  LHASH_NODE *ptr;
  uint uVar2;
  LHASH_NODE **ptr_00;
  uint uVar3;
  
  if (lh == (_LHASH *)0x0) {
    return;
  }
  uVar2 = lh->num_nodes;
  ptr_00 = lh->b;
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      ptr = ptr_00[uVar3];
      if (ptr != (LHASH_NODE *)0x0) {
        do {
          plVar1 = ptr->next;
          CRYPTO_free(ptr);
          ptr = plVar1;
        } while (plVar1 != (lhash_node_st *)0x0);
        ptr_00 = lh->b;
        uVar2 = lh->num_nodes;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  CRYPTO_free(ptr_00);
  CRYPTO_free(lh);
  return;
}

