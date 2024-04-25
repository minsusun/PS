def solution(friends, gifts):
    friend_table = {k: v for v, k in enumerate(friends)}
    n_friends = len(friends)
    
    gift_record = [[0 for _ in range(n_friends)] for _ in range(n_friends)]
    gift_fig = [0 for _ in range(n_friends)]
    gift_next_month = [0 for _ in range(n_friends)]
    
    for trans in gifts:
        sender, receiver = trans.split()
        sender = friend_table[sender]
        receiver = friend_table[receiver]
        gift_record[sender][receiver] += 1;
        gift_fig[sender] += 1;
        gift_fig[receiver] -= 1;
    
    for sender in range(n_friends):
        for receiver in range(sender + 1, n_friends):
            if sender == receiver:
                continue
            if gift_record[sender][receiver] != gift_record[receiver][sender]:
                dst = sender if gift_record[sender][receiver] > gift_record[receiver][sender] else receiver
                gift_next_month[dst] += 1;
            elif gift_fig[sender] != gift_fig[receiver]:
                dst = sender if gift_fig[sender] > gift_fig[receiver] else receiver
                gift_next_month[dst] += 1
    
    answer = max(gift_next_month)
    return answer
