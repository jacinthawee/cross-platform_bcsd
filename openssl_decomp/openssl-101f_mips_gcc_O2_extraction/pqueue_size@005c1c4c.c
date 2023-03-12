
int pqueue_size(pqueue pq)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  for (iVar2 = *(int *)pq; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

