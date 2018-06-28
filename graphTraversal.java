



public class Solution {
	Map<Integer, XVector> xvectorsForRows = new HashMap<>();

	public int FindMaxVisibleFromAnyPoint(char[][] matrix) {
		
		int maxCount = 0;
		for (int column = 0; column < matrix.length; column++) {
			int columnScore = 0;
			int maxIntersectingScore = 0;

				for (int row = 0; row <= matrix[column].length; row++) {
					if (row == matrix[column].length) {
						maxCount = Math.max(maxCount, columnScore + maxIntersectingScore);
						break;
					}

					switch (matrix[column][row]) {
					case ' ':
						if (!xVectorIntersects(column, row)) {
							calculateIntersectingVector(matrix, column, row);
						}
						maxIntersectingScore = Math.max(maxIntersectingScore, xvectorsForRows.get(row).score);
						break;
						
					case '*':
						columnScore++;
						if (!xVectorIntersects(column, row)) {
							calculateIntersectingVector(matrix, column, row);
						}
						// score - 1 so we don't double count the asterisk
						maxIntersectingScore = Math.max(maxIntersectingScore, xvectorsForRows.get(row).score - 1);
						break;
						
					case 'W':
						maxCount = Math.max(maxCount, columnScore + maxIntersectingScore);
						columnScore = 0;
						maxIntersectingScore = 0;
						break;
					}
				}
		}

		return maxCount;
	}

	private void calculateIntersectingVector(char[][] matrix, int column, int row) {
		int vectorScore = 0;
		int endPoint = column + 1;

		for (int i = column; i < matrix.length && matrix[i][row] != 'W'; i++) {
			if (matrix[i][row] == '*') vectorScore++;
			endPoint++;
		}

		xvectorsForRows.put(row, new XVector(column, endPoint, vectorScore));
	}

	private boolean xVectorIntersects(int column, int row) {
		if (xvectorsForRows.containsKey(row)) {
			return (xvectorsForRows.get(row).pointIntersects(column));
		}
		return false;
	}

	private class XVector {
		int start;
		int end;
		int score;

		XVector(int start, int end, int score) {
			this.start = start;
			this.end = end;
			this.score = score;
		}

		boolean pointIntersects(int column) {
			return (column >= start && column < end);
		}
	}
}