def solution(board):
    answer = board[0][0]

    for i,row in enumerate(board):
        for j,col in enumerate(row):
            if (i-1>=0 and j-1>=0) and board[i][j]:
                board[i][j] = min([board[i-1][j-1],board[i-1][j],board[i][j-1]])+1
                answer = max(board[i][j]**2,answer)

    return answer