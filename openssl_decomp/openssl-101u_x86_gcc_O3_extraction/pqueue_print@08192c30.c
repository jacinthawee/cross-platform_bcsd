
void pqueue_print(pqueue pq)

{
  undefined *puVar1;
  
  for (puVar1 = *(undefined **)pq; puVar1 != (undefined *)0x0;
      puVar1 = *(undefined **)(puVar1 + 0xc)) {
    __printf_chk(1,"item\t%02x%02x%02x%02x%02x%02x%02x%02x\n",*puVar1,puVar1[1],puVar1[2],puVar1[3],
                 puVar1[4],puVar1[5],puVar1[6],puVar1[7]);
  }
  return;
}

