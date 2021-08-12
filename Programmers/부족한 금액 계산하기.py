def solution(price, money, count):
    answer = -1
    
    answer = (price)*(count+1) * (count / 2) - money
    
    if(answer < 0):
        answer = 0

    return answer